// B - Prima Ke-K
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define PRIMES 77777
#define PRIME_MAX 989999 // the 77777th prime number is 989999

bool eliminated[PRIME_MAX + 1];
int64 primeNumbers[PRIMES + 1];

void sieveOfErastothenes(int64 n) {
    memset(eliminated, 0, sizeof(eliminated));
    memset(primeNumbers, 0, sizeof(primeNumbers));
    int prime = 0;
    for (int64 i = 2; i <= n; i++) {
        if (!eliminated[i]) {
            primeNumbers[prime++] = i;
            for (int64 j = i * i; j < n; j += i) {
                eliminated[j] = true;
            }
        }
    }
}

int main() {
    sieveOfErastothenes(PRIME_MAX);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int K;
        cin >> K;
        cout << primeNumbers[K - 1] << endl;
    }

    return 0;
}
