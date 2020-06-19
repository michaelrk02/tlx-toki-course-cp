// C - Pasar Rakyat
#include <iostream>

using namespace std;

typedef long long int64;

int64 gcd(int64 a, int64 b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int64 lcm(int64 a, int64 b) {
    return a * b / gcd(a, b);
}

int main() {
    int N;
    cin >> N;

    int64 Dprev = -1;
    for (int i = 0; i < N; i++) {
        int64 D;
        cin >> D;

        if (Dprev != -1) {
            Dprev = lcm(Dprev, D);
        } else {
            Dprev = D;
        }
    }

    cout << Dprev << endl;

    return 0;
}
