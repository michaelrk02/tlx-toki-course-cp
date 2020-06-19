// A - Penjumlahan Pecahan
#include <iostream>

using namespace std;

typedef long long int64;

int64 gcd(int64 a, int64 b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

struct rational_t {
    int64 numerator;
    int64 denominator;
};

rational_t add(rational_t a, rational_t b) {
    rational_t result;
    result.denominator = a.denominator * b.denominator;
    result.numerator = b.denominator * a.numerator + a.denominator * b.numerator;
    return result;
}

rational_t simplify(rational_t r) {
    int64 gcdval;
    while ((gcdval = gcd(r.numerator, r.denominator)) != 1) {
        r.numerator /= gcdval;
        r.denominator /= gcdval;
    }
    return r;
}

int main() {
    rational_t a, b;
    cin >> a.numerator >> a.denominator;
    cin >> b.numerator >> b.denominator;

    rational_t result = simplify(add(a, b));
    cout << result.numerator << " " << result.denominator << endl;

    return 0;
}
