// I - Terpendek Ke-K
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());

    cout << data[K - 1] << endl;

    return 0;
}
