// C - Perkalian Skalar
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

typedef long long llong;

int main() {
    int N;
    cin >> N;

    vector<llong> v1(N);
    for (int i = 0; i < N; i++) {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end(), less<llong>());

    vector<llong> v2(N);
    for (int i = 0; i < N; i++) {
        cin >> v2[i];
    }
    sort(v2.begin(), v2.end(), greater<llong>());

    llong product = 0;
    for (int i = 0; i < N; i++) {
        product = product + v1[i] * v2[i];
    }
    cout << product << endl;

    return 0;
}

