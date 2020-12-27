#include <deque>
#include <iostream>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main() {
    int N;
    cin >> N;

    int B;
    cin >> B;

    priority_queue<int, deque<int>, less<int>> pq;
    for (int i = 0; i < N; i++) {
        int H;
        cin >> H;
        pq.push(H);
    }

    int total = 0;
    while (B > 0) {
        B = B - pq.top();
        pq.pop();
        total++;
    }

    cout << total << endl;

    return 0;
}

