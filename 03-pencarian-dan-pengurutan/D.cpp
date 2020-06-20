// D - Pendataan Berat Bebek
#include <iostream>
#include <vector>

using namespace std;

int findPositionEx(const vector<int> &data, int x, int left, int right) {
    int middle = (left + right) / 2;
    if (left >= right) {
        if (x < data[middle]) {
            return middle;
        } else if (x > data[middle]) {
            return middle + 1;
        }
    }
    if (x < data[middle]) {
        return findPositionEx(data, x, left, middle - 1);
    } else if (x > data[middle]) {
        return findPositionEx(data, x, middle + 1, right);
    }
    return middle;
}

int findPosition(const vector<int> &data, int x) {
    int pos = findPositionEx(data, x, 0, data.size() - 1);
    return pos;
}

// (a,b]
int solve(const vector<int> &data, int a, int b) {
    a++;

    int aPos = findPosition(data, a);
    while ((aPos > 0) && (data[aPos - 1] == a)) {
        aPos--;
    }

    int bPos = findPosition(data, b);
    while ((bPos < data.size() - 1) && (data[bPos + 1] == b)) {
        bPos++;
    }
    if (data[bPos] == b) {
        bPos++;
    }

    return bPos - aPos;
}

int main() {
    int N;
    cin >> N;

    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int X, Y;
        cin >> X >> Y;
        cout << solve(data, X, Y) << endl;
    }

    return 0;
}

