#include <deque>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

typedef long long llong;

#define ABS(x) (((x) < 0) ? -(x) : (x))

int main() {
    int N;
    cin >> N;

    priority_queue<int, deque<int>, less<int>> v1pos;
    priority_queue<int, deque<int>, greater<int>> v1neg;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x >= 0) {
            v1pos.push(x);
        } else {
            v1neg.push(x);
        }
    }

    priority_queue<int, deque<int>, less<int>> v2pos;
    priority_queue<int, deque<int>, greater<int>> v2neg;
    for (int i = 0; i < N; i++) {
        int y;
        cin >> y;
        if (y >= 0) {
            v2pos.push(y);
        } else {
            v2neg.push(y);
        }
    }

    llong product = 0;
    while (!v1neg.empty() && !v2pos.empty()) {
        product = product + (llong)v1neg.top() * (llong)v2pos.top();
        v1neg.pop();
        v2pos.pop();
    }
    while (!v1pos.empty() && !v2neg.empty()) {
        product = product + (llong)v1pos.top() * (llong)v2neg.top();
        v1pos.pop();
        v2neg.pop();
    }

    priority_queue<int, deque<int>, less<int>> v1left;
    priority_queue<int, deque<int>, greater<int>> v2left;
    while (!v1pos.empty() && !v2pos.empty()) {
        v1left.push(v1pos.top());
        v2left.push(v2pos.top());
        v1pos.pop();
        v2pos.pop();
    }
    while (!v1neg.empty() && !v2neg.empty()) {
        v1left.push(v1neg.top());
        v2left.push(v2neg.top());
        v1neg.pop();
        v2neg.pop();
    }
    while (!v1left.empty() && !v2left.empty()) {
        product = product + (llong)v1left.top() * (llong)v2left.top();
        v1left.pop();
        v2left.pop();
    }
    cout << product << endl;

    return 0;
}

