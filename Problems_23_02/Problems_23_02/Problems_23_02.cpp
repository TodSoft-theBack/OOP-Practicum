#include <iostream>

struct complex {

    static const char i = 'i';
    double real = 0;
    double imaginary = 0;

    complex operator+(const complex & c) {
        complex res;
        res.real =  real + c.real;
        res.imaginary = imaginary + c.imaginary;
        return res;
    }
    complex operator*(const complex& c) {
        complex res;
        res.real = real * c.real - imaginary * c.imaginary;
        res.imaginary = real * c.imaginary + imaginary * c.real;
        return res;
    }
};

complex Add(const complex& c_1, const complex& c_2) {
    complex res;
    res.real = c_1.real + c_2.real;
    res.imaginary = c_1.imaginary + c_2.imaginary;
    return res;
}

complex Multiply(const complex& c_1, const complex& c_2) {
    complex res;
    res.real = c_1.real * c_2.real - c_1.imaginary * c_2.imaginary;
    res.imaginary = c_1.real * c_2.imaginary + c_1.imaginary * c_2.real;
    return res;
}

void Print(const complex& c) {
    using std::cout;
    using std::endl;
    if (c.real == 0.00 || c.imaginary == 0.00)
    {
        double value = c.real + c.imaginary;
        if (c.imaginary != 0.00)
        {
            if (value == 1.0)
                cout << complex::i;
            else
                cout << value << complex::i;
        }
        else
            cout << value;
        cout << endl;
        return;
    }
    cout << "< ";
    cout << c.real;
    cout << " + " << c.imaginary << "i >" << endl;
}

int main()
{
    complex a{1, 0}, b{0,1};
    complex c = Add(a, b);
    Print(a);
    Print(b);
    Print(c);
    c = a + b;
    Print(c);
}
