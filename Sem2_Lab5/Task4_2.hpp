#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
class Polynomial {
private:
    std::vector<T> coeffs;
    void trim() {
        while (!coeffs.empty() && coeffs.back() == T(0))
            coeffs.pop_back();
    }
public:
    Polynomial() = default;
    Polynomial(const std::vector<T>& vec) : coeffs(vec) { trim(); }
    Polynomial(const T& scalar) {
        if (scalar != T(0)) coeffs.push_back(scalar);
    }

    int Degree() const { return static_cast<int>(coeffs.size()) - 1; }

    const T& operator[](size_t deg) const {
        static const T zero = T(0);
        return (deg < coeffs.size()) ? coeffs[deg] : zero;
    }

    bool operator==(const Polynomial& other) const {
        Polynomial a = *this, b = other;
        a.trim(); b.trim();
        return a.coeffs == b.coeffs;
    }
    bool operator!=(const Polynomial& other) const { return !(*this == other); }

    Polynomial operator+(const Polynomial& other) const {
        size_t n = std::max(coeffs.size(), other.coeffs.size());
        std::vector<T> res(n, T(0));
        for (size_t i = 0; i < coeffs.size(); ++i) res[i] = coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) res[i] = res[i] + other.coeffs[i];
        return Polynomial(res);
    }
    Polynomial operator-(const Polynomial& other) const {
        size_t n = std::max(coeffs.size(), other.coeffs.size());
        std::vector<T> res(n, T(0));
        for (size_t i = 0; i < coeffs.size(); ++i) res[i] = coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) res[i] = res[i] - other.coeffs[i];
        return Polynomial(res);
    }
    Polynomial operator*(const Polynomial& other) const {
        if (coeffs.empty() || other.coeffs.empty()) return Polynomial();
        std::vector<T> res(coeffs.size() + other.coeffs.size() - 1, T(0));
        for (size_t i = 0; i < coeffs.size(); ++i)
            for (size_t j = 0; j < other.coeffs.size(); ++j)
                res[i + j] = res[i + j] + coeffs[i] * other.coeffs[j];
        return Polynomial(res);
    }

    Polynomial& operator+=(const Polynomial& other) { *this = *this + other; return *this; }
    Polynomial& operator*=(const Polynomial& other) { *this = *this * other; return *this; }

    T operator()(const T& x) const {
        T result = T(0);
        for (int i = Degree(); i >= 0; --i)
            result = result * x + coeffs[i];
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.coeffs.empty()) { os << "0"; return os; }
        for (int i = p.Degree(); i >= 0; --i) {
            os << p[i];
            if (i > 0) os << " ";
        }
        return os;
    }

    friend Polynomial operator+(const T& scalar, const Polynomial& p) { return Polynomial(scalar) + p; }
    friend Polynomial operator-(const T& scalar, const Polynomial& p) { return Polynomial(scalar) - p; }
    friend Polynomial operator*(const T& scalar, const Polynomial& p) { return Polynomial(scalar) * p; }
};

#endif
