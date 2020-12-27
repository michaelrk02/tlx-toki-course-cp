// B - Pangkat Besar
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

unsigned long long fastexp(unsigned long long x, unsigned long long y, unsigned long long mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return fastexp((x % mod) * (x % mod), y / 2, mod);
    }
    return ((x % mod) * (fastexp((x % mod) * (x % mod), y / 2, mod) % mod)) % mod;
}

int main() {
    unsigned long long A, B;
    cin >> A >> B;

    unsigned long long result = fastexp(A, B, 1000000);
    if ((double)B >= 6.0 / log10(A)) {
        cout << setw(6) << setfill('0');
    }
    cout << result << endl;

    return 0;
}

