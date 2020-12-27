// B - Jamuan Makan
#include <deque>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < N; i++) {
        int S, D;
        cin >> S >> D;
        pq.push(pair<int, int>(S + D - 1, S));
    }

#ifdef DEBUG
    queue<pair<int, int>> temp;
    while (!pq.empty()) {
        pair<int, int> val = pq.top();
        cout << "(" << val.first << ", " << val.second << ")";
        temp.push(val);
        pq.pop();
    }
    cout << endl;
    while (!temp.empty()) {
        pq.push(temp.front());
        temp.pop();
    }
#endif

    int timestamp = 0;
    int count = 0;
    while (!pq.empty()) {
        if (pq.top().second >= timestamp) {
            timestamp = pq.top().first + 1;
            count++;
        }
        pq.pop();
    }
    cout << count << endl;

    return 0;
}

