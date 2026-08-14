#include "catch.hpp"

#include "oop_complex.h"

#include <complex>
#include <sstream>
#include <type_traits>


void Check(const Complex& actual, const std::complex<double>& expected) {
    REQUIRE(std::fabs(actual.Real() - expected.real()) < 1e9);
    REQUIRE(std::fabs(actual.Imag() - expected.imag()) < 1e9);
}

TEST_CASE("Complex has constructors", "[oop_complex]") {
    {
        INFO("default ctor");
        Complex z;
        Check(z, std::complex<double>());
    }
    {
        INFO("user-defined ctors");
        Complex a(1);
        Check(a, std::complex<double>(1));

        Complex b(0, 1);
        Check(b, std::complex<double>(0, 1));

        Complex z(3, 4);
        Check(z, std::complex<double>(3, 4));
    }
    {
        INFO("copy ctor");
        Complex z(3, 4);
        Complex y = z;
        Check(y, std::complex<double>(3, 4));
    }
}

TEST_CASE("Basic methods", "[oop_complex]") {
    Complex z(3, 4);
    REQUIRE(z.Real() == 3);
    REQUIRE(z.Imag() == 4);
    REQUIRE(z.Abs() == 5);

    z.Real(5);
    z.Imag(12);

    REQUIRE(z.Real() == 5);
    REQUIRE(z.Imag() == 12);
    REQUIRE(z.Abs() == 13);
}


TEST_CASE("Copy correctness", "[oop_complex]") {
    Complex a;
    Complex b(a);
    b.Imag(1);
    Check(a, std::complex<double>());
    Check(b, std::complex<double>{0, 1});

    b = b;
    Check(b, std::complex<double>{0, 1});
    a = b;
    Check(a, std::complex<double>{0, 1});

    b = a;
    Check(b, std::complex<double>{0, 1});
    Complex c(b);
    Check(c, std::complex<double>{0, 1});
}


TEST_CASE("Unary plus/minus", "[complex]") {
    Complex z(3, 4);
    Check(+z, std::complex<double>(3, 4));
    Check(-z, std::complex<double>(-3, -4));
}


TEST_CASE("Arithmetics", "[complex]") {
    INFO("addition") {
        Complex z1(3, 4);
        Complex z2(2, -1);
        Check(z1 + z2, std::complex<double>(5, 3));
        Complex sum = z1 + z2;
        Check(sum, std::complex<double>(5, 3));

        z1 += z2;
        Check(z1, std::complex<double>(5, 3));

        z2 += 5;
        Check(z2, std::complex<double>(7, -1));
    }

    INFO("subtraction") {
        Complex z1(5, 2);
        Complex z2(3, -4);
        Check(z1 - z2, std::complex<double>(2, 6));
        Complex sub = z1 - z2;
        Check(sub, std::complex<double>(2, 6));

        z1 -= z2;
        Check(z1, std::complex<double>(2, 6));

        z2 -= 5;
        Check(z2, std::complex<double>(-2, -4));
    }
    
    INFO("multiplication") {
        Complex z1(2, 3);
        Complex z2(4, 5);
        Check(z1 * z2, std::complex<double>(-7, 22));
        Complex mul = z1 * z2;
        Check(mul, std::complex<double>(-7, 22));

        z1 *= z2;
        Check(z1, std::complex<double>(-7, 22));

        z2 *= 5;
        Check(z2, std::complex<double>(20, 25));
    }

    INFO("division") {
        Complex z1(5, 5);
        Complex z2(1, 2);
        Check(z1 / z2, std::complex<double>(3, -1));
        Complex sum = z1 / z2;
        Check(sum, std::complex<double>(3, -1));

        z1 /= z2;
        Check(z1, std::complex<double>(3, -1));

        Complex z3(3, 3);
        z3 /= 3;
        Check(z3, std::complex<double>(1, 1));
    }
}
