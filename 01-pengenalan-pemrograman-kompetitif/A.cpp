#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifdef DEBUG
#define _DBG(x) x
#else
#define _DBG(x)
#endif

#define _TRACE(x) _DBG(cout << x << endl)

struct participant_t {
    string id;
    int s1, s2, s3;
};

bool p1GreaterThanP2(const participant_t &p1, const participant_t &p2) {
    if (p1.s3 == p2.s3) {
        if (p1.s2 == p2.s2) {
            return p1.s1 > p2.s1;
        }
        return p1.s2 > p2.s2;
    }
    return p1.s3 > p2.s3;
}

void swap(participant_t &p1, participant_t &p2) {
    participant_t temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
}

int partition(vector<participant_t> &arr, int left, int right) {
    participant_t pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (true) {
        while (p1GreaterThanP2(arr[i], pivot)) {
            i++;
        }
        while (p1GreaterThanP2(pivot, arr[j])) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }

    return -1;
}

void sort(vector<participant_t> &arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int p = partition(arr, left, right);
    if (p != -1) {
        sort(arr, left, p);
        sort(arr, p + 1, right);
    }
}

void print(const vector<participant_t> &arr) {
    cout << "=== standings ===" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i].id << " " << arr[i].s1 << " " << arr[i].s2 << " " << arr[i].s3 << endl;
    }
    cout << endl;
}

int main() {
    int T;

    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M;
        string id;

        cin >> N >> M >> id;
        vector<participant_t> participants(N);
        for (int i = 0; i < N; i++) {
            cin >> participants[i].id;
            cin >> participants[i].s1;
            cin >> participants[i].s2;
            cin >> participants[i].s3;
        }
        sort(participants, 0, N - 1);
        _DBG(print(participants));

        bool pass = false;
        for (int i = 0; i < M; i++) {
            if (participants[i].id == id) {
                pass = true;
                break;
            }
        }
        cout << (pass ? "YA" : "TIDAK") << endl;
    }

    return 0;
}

