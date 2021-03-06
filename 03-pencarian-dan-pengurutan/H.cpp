// H - Membeli Beras
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<pair<double, int>> riceData(N);
    for (int i = 0; i < N; i++) {
        cin >> riceData[i].second;
    }
    for (int i = 0; i < N; i++) {
        int cost;
        cin >> cost;
        riceData[i].first = (double)cost / riceData[i].second;
    }

    sort(riceData.begin(), riceData.end());

    double price = 0.0;
    while ((X > 0) && (riceData.size() > 0)) {
        pair<double, int> &last = riceData.back();
        price += last.first;
        X--;
        if (--last.second == 0) {
            riceData.pop_back();
        }
    }

    cout.precision(5);
    cout << fixed << price << endl;

    return 0;
}
