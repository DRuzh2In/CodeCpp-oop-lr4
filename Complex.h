#pragma once
#include <cmath>
#include "iostream"

using namespace std;
class Complex {

private:
    double re;
    double im;

public:

    Complex() {
    }
    Complex(double re, double im) : re(re), im(im) {}

    ~Complex() {}

    double get_re() {
        return re;
    }

    void set_re(double re) {
        this->re = re;
    }

    double get_im() {
        return im;
    }

    void set_im(double im) {
        this->im = im;
    }

    template<class Type>
    // Multiplication of complex numbers
    static Type mult(Type z1, Type z2) {
        double re = z1.get_re() * z2.get_re() - z1.get_im() * z2.get_im();
        double im = z1.get_im() * z2.get_im() + z1.get_re() * z2.get_re();
        return Type(re, im);
    }

    template<class Type>
    // Sum of complex numbers
    static Type sum(Type z1, Type z2) {
        int re = z1.get_re() + z2.get_re();
        int im = z1.get_im() + z2.get_im();
        return Type(re, im);
    }

    template<class Type>
    // Subtraction of complex numbers
    static Type sub(Type z1, Type z2) {
        double re = z1.get_re() - z2.get_re();
        double im = z1.get_im() - z2.get_im();
        return Type(re, im);
    }

    template<class Type>
    // Division of complex numbers
    static Type div(Type z1, Type z2) {
        double re = (z1.get_re() * z2.get_re() + z1.get_im() * z2.get_im()) /
                    (z2.get_re() * z2.get_re() + z2.get_im() * z2.get_im());
        double im = (z1.get_im() * z2.get_re() - z1.get_re() * z2.get_im()) /
                    (z2.get_re() * z2.get_re() + z2.get_im() * z2.get_im());
        return Type(re, im);
    }

    template<class Type>
    // Module of complex number
    static Type mod(Type z) {
        double res = sqrt(z.get_re() * z.get_re() + z.get_im() * z.get_im());
        return res;
    }

    friend ostream &operator<<(ostream &out, Complex &z) {
        if (z.get_im() < 0) {
            out << "COMPLEX NUMBER: " << z.get_re() << " + (" << z.get_im() << ")i; " << endl;
        } else {
            out << "COMPLEX NUMBER: " << z.get_re() << " + " << z.get_im() << "i; " << endl;
        }
        return out;
    }
};
