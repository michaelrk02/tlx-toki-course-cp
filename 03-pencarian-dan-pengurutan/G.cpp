// G - Kualitas Baju
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());

    float median;
    if (data.size() % 2 == 0) {
        median = ((float)data[N / 2 - 1] + (float)data[N / 2]) / 2.0f;
    } else {
        median = (float)data[N / 2];
    }

    cout.precision(1);
    cout << fixed << median << endl;

    return 0;
}

