namespace mathlib {

    template<typename T>
    class Fraction {
    private:
        T numerator;
        T denominator;

        void enforceNonZeroDenominator() {
            if (denominator == 0) {
                throw std::invalid_argument("Denominator can't be 0.");
            }
        }

    public:
        Fraction(T num = 0, T denom = 1) : numerator(num), denominator(denom) {
            enforceNonZeroDenominator();
            simplify();
        }

        void simplify() {
            T gcd = std::gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
        }

        double toDouble() const {
            return static_cast<double>(numerator) / denominator;
        }

        Fraction operator+(const Fraction& other) const {
            return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
        }

        Fraction operator-(const Fraction& other) const {
            return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
        }

        Fraction operator*(const Fraction& other) const {
            return Fraction(numerator * other.numerator, denominator * other.denominator);
        }

        Fraction operator/(const Fraction& other) const {
            if (other.numerator == 0) {
                throw std::domain_error("Divided by 0.");
            }
            return Fraction(numerator * other.denominator, denominator * other.numerator);
        }

        bool operator==(const Fraction& other) const {
            return numerator == other.numerator && denominator == other.denominator;
        }

        bool operator!=(const Fraction& other) const {
            return !(*this == other);
        }

        bool operator<(const Fraction& other) const {
            return numerator * other.denominator < other.numerator * denominator;
        }

        bool operator>(const Fraction& other) const {
            return other < *this;
        }

        bool operator<=(const Fraction& other) const {
            return !(other < *this);
        }

        bool operator>=(const Fraction& other) const {
            return !(*this < other);
        }

        friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
            os << frac.numerator << '/' << frac.denominator;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Fraction& frac) {
            T num, denom;
            char slash;
            is >> num >> slash >> denom;
            if (slash != '/' || denom == 0) {
                is.setstate(std::ios::failbit);
            }
            else {
                frac = Fraction(num, denom);
            }
            return is;
        }
    };

} 