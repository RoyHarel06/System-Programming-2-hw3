#include "Fraction.hpp"

#include <algorithm>
#include <limits>
// numeric_limits<int>::max()

namespace ariel
{
    int Fraction::safe_addition(int num1, int num2) const{
        if (num1 == 0)
            return num2;
        if (num2 == 0)
            return num1;

        if ((num2 > 0 && num1 > numeric_limits<int>::max() - num2) ||
            (num2 < 0 && num1 < numeric_limits<int>::min() - num2))
            throw overflow_error("Integer overflow! ");

        return num1 + num2;
    }
    int Fraction::safe_subtract(int num1, int num2) const{
        if (num1 == 0)
            return -num2;
        if (num2 == 0)
            return num1;

        if ((num2 < 0 && num1 > numeric_limits<int>::max() + num2) ||
            (num2 > 0 && num1 < numeric_limits<int>::min() + num2))
            throw overflow_error("Integer overflow! ");

        return num1 - num2;
    }
    int Fraction::safe_multiply(int num1, int num2) const {
        
        if (num1 == 0 || num2 == 0)
            return 0;

        if ((num2 > 0 && num1 > numeric_limits<int>::max() / num2) ||
            (num2 < 0 && num1 < numeric_limits<int>::max() / num2))
            throw overflow_error("Integer overflow!");

        return num1 * num2;
    }

    void Fraction::reduce() {
        int gcd = __gcd(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        
        if (denominator < 0) {
            // generally trying to keep the sign in the numerator
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Constructors:

    Fraction::Fraction() {
        this->numerator = 0;
        this->denominator = 1;
    }
    Fraction::Fraction(int numerator_in, int denominator_in): numerator(numerator_in), denominator(denominator_in) {
        if (denominator == 0)
            throw invalid_argument("Denominator can't be zero!");

        reduce();
    }
    Fraction::Fraction(float other): numerator(int(other*1000)), denominator(1000) {
        reduce();
    }
    Fraction::Fraction(const Fraction& other): numerator(other.getNumerator()), denominator(other.getDenominator()) {
        if (denominator == 0)
            throw runtime_error("Denominator can't be zero!");

        reduce();
    }

    // Copy assignment operator:

    Fraction& Fraction::operator=(const Fraction& other) {
        numerator = other.getNumerator();
        denominator = other.getDenominator();
        reduce();

        return (*this);
    }

    // Move constructor and assignment operator:

    Fraction::Fraction(Fraction&& other) noexcept {
        numerator = other.getNumerator();
        denominator = other.getDenominator();
        reduce();

        other.setNumerator(0);
        other.setDenominator(1);
    }
    Fraction& Fraction::operator=(Fraction&& other) noexcept {
        if (this != &other) {
            numerator = other.getNumerator();
            denominator = other.getDenominator();
            reduce();

            other.setNumerator(0);
            other.setDenominator(1);
        }
        return (*this);
    }

    // Get and Set functions:

    int Fraction::getNumerator() const {
        return numerator;
    }
    int Fraction::getDenominator() const {
        return denominator;
    }

    void Fraction::setNumerator(int numerator) {
        this->numerator = numerator;
        reduce();
    }
    void Fraction::setDenominator(int denominator) {
        this->denominator = denominator;
        reduce();
    }

    // Arithmetic operators:

    Fraction Fraction::operator-() const {
        return Fraction(-numerator, denominator);
    }

    Fraction Fraction::operator+(const Fraction& other) const {
        int a = safe_multiply(numerator, other.getDenominator());
        int b = safe_multiply(other.getNumerator(), denominator);

        return Fraction(safe_addition(a, b), safe_multiply(denominator, other.getDenominator()));
    }
    Fraction Fraction::operator-(const Fraction& other) const {
        int a = safe_multiply(numerator, other.getDenominator());
        int b = safe_multiply(other.getNumerator(), denominator);

        return Fraction(safe_subtract(a, b), safe_multiply(denominator, other.getDenominator()));
    }
    Fraction Fraction::operator*(const Fraction& other) const {
        int numerator = safe_multiply(this->numerator, other.getNumerator());
        int denominator = safe_multiply(this->denominator, other.getDenominator());

        return Fraction(numerator, denominator);
    }
    Fraction Fraction::operator/(const Fraction& other) const {
        if (other.getNumerator() == 0)
            throw runtime_error("Can't divide by zero!");

        int numerator = safe_multiply(this->numerator, other.getDenominator());
        int denominator = safe_multiply(this->denominator, other.getNumerator());

        return Fraction(numerator, denominator);
    }

    Fraction Fraction::operator+(const float& other) const {
        Fraction otherFraction(other);
        return (*this) + otherFraction;
    }
    Fraction Fraction::operator-(const float& other) const {
        Fraction otherFraction(other);
        return (*this) - otherFraction;
    }
    Fraction Fraction::operator*(const float& other) const {
        Fraction otherFraction(other);
        return (*this) * otherFraction;
    }
    Fraction Fraction::operator/(const float& other) const {
        Fraction otherFraction(other);
        return (*this) / otherFraction;
    }

    const Fraction operator+(const float& number, const Fraction& fraction) {
        Fraction number_fraction(number);
        return number_fraction + fraction;
    }
    const Fraction operator-(const float& number, const Fraction& fraction) {
        Fraction number_fraction(number);
        return number_fraction - fraction;
    }
    const Fraction operator*(const float& number, const Fraction& fraction) {
        Fraction number_fraction(number);
        return number_fraction * fraction;
    }
    const Fraction operator/(const float& number, const Fraction& fraction) {
        Fraction number_fraction(number);
        return number_fraction / fraction;
    }

    // Comparison operators:

    bool Fraction::operator==(const Fraction& other) const {
        Fraction this_reduced(*this);
        Fraction other_reduced(other);

        return (this_reduced.getNumerator() == other_reduced.getNumerator() &&
                this_reduced.getDenominator() == other_reduced.getDenominator());
    }
    bool Fraction::operator!=(const Fraction& other) const {
        return !( (*this) == other );
    }
    bool Fraction::operator<(const Fraction& other) const {
        int a = this->numerator * other.getDenominator();
        int b = other.getNumerator() * this->denominator;

        return a < b;
    }
    bool Fraction::operator>(const Fraction& other) const {
        return other < (*this);
    }
    bool Fraction::operator<=(const Fraction& other) const {
        return (*this) < other || (*this) == other;
    }
    bool Fraction::operator>=(const Fraction& other) const {
        return (*this) > other || (*this) == other;
    }

    bool Fraction::operator==(const float& other) const {
        return (*this) == Fraction(other);
    }
    bool Fraction::operator!=(const float& other) const {
        return (*this) != Fraction(other);
    }
    bool Fraction::operator<(const float& other) const {
        return (*this) < Fraction(other);
    }
    bool Fraction::operator>(const float& other) const {
        return (*this) > Fraction(other);
    }
    bool Fraction::operator<=(const float& other) const {
        return (*this) <= Fraction(other);
    }
    bool Fraction::operator>=(const float& other) const {
        return (*this) >= Fraction(other);
    }

    const bool operator==(const float& number, const Fraction& fraction) {
        return fraction == number;
    }
    const bool operator!=(const float& number, const Fraction& fraction) {
        return fraction != number;
    }
    const bool operator<(const float& number, const Fraction& fraction) {
        return fraction > number;
    }
    const bool operator>(const float& number, const Fraction& fraction) {
        return fraction < number;
    }
    const bool operator<=(const float& number, const Fraction& fraction) {
        return fraction >= number;
    }
    const bool operator>=(const float& number, const Fraction& fraction) {
        return fraction <= number;
    }

    // Prefix increment and decrement operators:

    Fraction& Fraction::operator++() {
        numerator = safe_addition(numerator, denominator);
        reduce();
        return *this;
    }
    Fraction& Fraction::operator--() {
        numerator = safe_addition(numerator, -denominator);
        reduce();
        return *this;
    }

    // Postfix increment and decrement operators:

    Fraction Fraction::operator++(int) {
        Fraction copy(*this);
        numerator = safe_addition(numerator, denominator);
        reduce();
        return copy;
    }
    Fraction Fraction::operator--(int) {
        Fraction copy(*this);
        numerator = safe_addition(numerator, -denominator);
        reduce();
        return copy;
    }

    // Output operator:

    ostream& operator<<(ostream& output, const Fraction& fraction) {
        output << fraction.getNumerator() << "/" << fraction.getDenominator();
        return output;
    }
    istream& operator>>(istream& input, Fraction& fraction) {
        int numerator, denominator;

        input >> numerator >> denominator;
        if (input.fail())
            throw runtime_error("Invalid input");
        if (denominator == 0)
            throw runtime_error("Denominator can't be zero!");

        fraction = Fraction(numerator, denominator);
        return input;
    }
}