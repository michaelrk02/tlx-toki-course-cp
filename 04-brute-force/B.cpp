/* This solution is still working in progress (score 71 of 100 [TLE]) T_T */
#include <cstring>
#include <iostream>

using namespace std;

struct team_t {
    int plays;
    int points;
};

bool solve(team_t *t, int N, int x, int y) {
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
                    if (!((i == x) && (j == y))) {
                        team_t *tperm = new team_t[N];

                        if (t[i].points >= 3) {
                            memcpy(tperm, t, N * sizeof(team_t));
                            tperm[i].plays--;
                            tperm[j].plays--;
                            tperm[i].points = tperm[i].points - 3;
                            result |= solve(tperm, N, i, j);
                        }

                        if (t[j].points >= 3) {
                            memcpy(tperm, t, N * sizeof(team_t));
                            tperm[i].plays--;
                            tperm[j].plays--;
                            tperm[j].points = tperm[j].points - 3;
                            result |= solve(tperm, N, i, j);
                        }

                        if ((t[i].points >= 1) && (t[j].points >= 1)) {
                            memcpy(tperm, t, N * sizeof(team_t));
                            tperm[i].plays--;
                            tperm[j].plays--;
                            tperm[i].points = tperm[i].points - 1;
                            tperm[j].points = tperm[j].points - 1;
                            result |= solve(tperm, N, i, j);
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

        team_t *tm = new team_t[N];
        for (int i = 0; i < N; i++) {
            tm[i].plays = N - 1;
            cin >> tm[i].points;
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
            cout << (solve(tm, N, -1, -1) ? "YES" : "NO") << endl;
            delete[] tm;
        }
    }

    return 0;
}

