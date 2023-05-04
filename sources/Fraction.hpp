#include <iostream>

namespace ariel
{
    class Fraction {
        private:
            int numerator;
            int denominator;

        public:
            // Constructors:
            Fraction();
            Fraction(int numerator, int denominator);
            Fraction(float other);
            Fraction(const Fraction& other);

            // Arithmetic operators:
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

            friend const Fraction operator==(const float& number, const Fraction& fraction);
            friend const Fraction operator!=(const float& number, const Fraction& fraction);
            friend const Fraction operator<(const float& number, const Fraction& fraction);
            friend const Fraction operator>(const float& number, const Fraction& fraction);
            friend const Fraction operator<=(const float& number, const Fraction& fraction);
            friend const Fraction operator>=(const float& number, const Fraction& fraction);

            // Prefix increment and decrement operators:
            Fraction& operator++();
            Fraction& operator--();
            // Postfix increment and decrement operators:
            Fraction operator++(int);
            Fraction operator--(int);

            // Input and output operators:
            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& is, Fraction& fraction);
    };
}