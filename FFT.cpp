#include <bits/stdc++.h>
using namespace std;

// Definiciones iniciales.

typedef vector<double> Vector;

const double M_2PI = 2 * M_PI;

// Tipo de dato para operar con numeros complejos.

struct Complejo {
    double real, imag;
    Complejo() : real(), imag() {}
    Complejo(double R, double I) : real(R), imag(I) {}

    Complejo operator+(const Complejo& c) {
        return Complejo(real + c.real, imag + c.imag); }
    Complejo operator-(const Complejo& c) {
        return Complejo(real - c.real, imag - c.imag); }
    Complejo operator*(const Complejo& c) {
        return Complejo(real * c.real - imag * c.imag,
                        real * c.imag + imag * c.real); }
};

// Transformada rapida de Fourier.
// Se tiene que garantizar que el numero de
// elementos en el vector sea una potencia de 2.

vector<Complejo> FastAndFourier(
    const vector<Complejo>& a, int k = 1) {

    int n = a.size();
    if (n == 1) return a;
    vector<Complejo> par, impar;
    for (int i = 0; i < n; ++i)
        if (i & 1) par.push_back(a[i]);
        else impar.push_back(a[i]);
    impar = FastAndFourier(impar, k);
    par = FastAndFourier(par, k);

    vector<Complejo> fourier(n);
    Complejo w(1, 0), wn(cos(-k * M_2PI/n),
                         sin(-k * M_2PI/n));
    for (int i = 0; i < n/2; w = w * wn, ++i) {
        fourier[i + n/2] = impar[i] - w * par[i];
        fourier[i] = impar[i] + w * par[i];
    }
    return fourier;
}

int main() {
    return 0;
}