/* This solution is still working in progress (score 86 of 100 [TLE]) T_T */
#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

#define PLAY(u, x)      u = u | (1 << ((x) & 0x1))
#define PLAYED(u, x)    ((((u) >> (x)) & 0x1) == 1)
//#define PLAY(u, x)
//#define PLAYED(u, x) false

struct team_t {
    int plays;
    int points;
    unsigned int played;
};

bool solve(team_t *t, int N) {
    bool gameOver = true;
    for (int i = 0; i < N; i++) {
        if (t[i].plays > 0) {
            gameOver = false;
            break;
        }
    }
    if (gameOver) {
        bool match = true;
        for (int i = 0; i < N; i++) {
            if (t[i].points > 0) {
                match = false;
                break;
            }
        }
        return match;
    }

    bool result = false;

    for (int i = 0; i < N - 1; i++) {
        if (t[i].plays > 0) {
            for (int j = i + 1; j < N ; j++) {
                if (t[j].plays > 0) {
                    if (!PLAYED(t[i].played, j) && !PLAYED(t[j].played, i)) {
                        team_t *tperm = new team_t[N];

                        if (t[i].points >= 3) {
                            memcpy(tperm, t, N * sizeof(team_t));
                            tperm[i].plays--;
                            tperm[j].plays--;
                            tperm[i].points = tperm[i].points - 3;
                            PLAY(tperm[i].played, j);
                            PLAY(tperm[j].played, i);
                            result = result || solve(tperm, N);
                        }

                        if (t[j].points >= 3) {
                            memcpy(tperm, t, N * sizeof(team_t));
                            tperm[i].plays--;
                            tperm[j].plays--;
                            tperm[j].points = tperm[j].points - 3;
                            PLAY(tperm[i].played, j);
                            PLAY(tperm[j].played, i);
                            result = result || solve(tperm, N);
                        }

                        if ((t[i].points >= 1) && (t[j].points >= 1)) {
                            memcpy(tperm, t, N * sizeof(team_t));
                            tperm[i].plays--;
                            tperm[j].plays--;
                            tperm[i].points = tperm[i].points - 1;
                            tperm[j].points = tperm[j].points - 1;
                            PLAY(tperm[i].played, j);
                            PLAY(tperm[j].played, i);
                            result = result || solve(tperm, N);
                        }

                        delete[] tperm;
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    int T;

    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i];
        }
        sort(points.begin(), points.end(), less<int>());

        team_t *tm = new team_t[N];
        for (int i = 0; i < N; i++) {
            tm[i].plays = N - 1;
            tm[i].points = points[i];
            tm[i].played = 0;
        }

        for (int i = 0; i < N; i++) {
            if (tm[i].points > 3 * (N - 1)) {
                cout << "NO" << endl;
                delete[] tm;
                tm = NULL;
                break;
            }
        }

        if (tm != NULL) {
            cout << (solve(tm, N) ? "YES" : "NO") << endl;
            delete[] tm;
        }
    }

    return 0;
}

