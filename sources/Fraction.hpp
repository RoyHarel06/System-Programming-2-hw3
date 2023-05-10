#include <iostream>

using namespace std;

namespace ariel
{
    class Fraction {
        private:
            int numerator;
            int denominator;
            void reduce();
            int safe_multiply(int num1, int num2) const;
            int safe_addition(int num1, int num2) const;
            int safe_subtract(int num1, int num2) const;

        public:
            // Constructors:
            Fraction();
            Fraction(int numerator_in, int denominator_in);
            Fraction(float other);
            Fraction(const Fraction& other);
            // Destructor: (for tidy)
            ~Fraction() = default;

            // Copy assignment operator:
            Fraction& operator=(const Fraction& other);
            // Move constructor and assignment operator:
            Fraction(Fraction&& other) noexcept;
            Fraction& operator=(Fraction&& other) noexcept;

            // Get and Set functions:
            int getNumerator() const;
            int getDenominator() const;

            void setNumerator(int numerator);
            void setDenominator(int denominator);

            // Arithmetic operators:
            Fraction operator-() const;

            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;

            Fraction operator+(const float& other) const;
            Fraction operator-(const float& other) const;
            Fraction operator*(const float& other) const;
            Fraction operator/(const float& other) const;

            friend const Fraction operator+(const float& number, const Fraction& fraction);
            friend const Fraction operator-(const float& number, const Fraction& fraction);
            friend const Fraction operator*(const float& number, const Fraction& fraction);
            friend const Fraction operator/(const float& number, const Fraction& fraction);

            // Comparison operators:
            bool operator==(const Fraction& other) const;
            bool operator!=(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator>(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;

            bool operator==(const float& other) const;
            bool operator!=(const float& other) const;
            bool operator<(const float& other) const;
            bool operator>(const float& other) const;
            bool operator<=(const float& other) const;
            bool operator>=(const float& other) const;

            friend const bool operator==(const float& number, const Fraction& fraction);
            friend const bool operator!=(const float& number, const Fraction& fraction);
            friend const bool operator<(const float& number, const Fraction& fraction);
            friend const bool operator>(const float& number, const Fraction& fraction);
            friend const bool operator<=(const float& number, const Fraction& fraction);
            friend const bool operator>=(const float& number, const Fraction& fraction);

            // Prefix increment and decrement operators:
            Fraction& operator++();
            Fraction& operator--();
            // Postfix increment and decrement operators:
            Fraction operator++(int);
            Fraction operator--(int);

            // Input and output operators:
            friend ostream& operator<<(ostream& output, const Fraction& fraction);
            friend istream& operator>>(istream& input, Fraction& fraction);
    };
}