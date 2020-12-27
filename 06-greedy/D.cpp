// D - Beli Cokelat
#include <deque>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef unsigned long long ullong;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main() {
    int N;
    ullong D;
    cin >> N >> D;

    priority_queue<pair<ullong, ullong>, deque<pair<ullong, ullong>>, greater<pair<ullong, ullong>>> pq;
    for (int i = 0; i < N; i++) {
        ullong H, B;
        cin >> H >> B;
        pq.push(pair<ullong, ullong>(H, B));
    }

    ullong count = 0;
    while (!pq.empty() && (D > 0)) {
        pair<ullong, ullong> p = pq.top();
        if (D < p.first) {
            break;
        }

        ullong cost = MIN(D, p.first * p.second);
        ullong buy = cost / p.first;
        if (D >= buy * p.first) {
            D = D - buy * p.first;
        } else {
            D = 0;
        }
        count = count + buy;

        pq.pop();
    }
    cout << count << endl;

    return 0;
}

