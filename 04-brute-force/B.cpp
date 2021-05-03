#include <cstring>
#include <iostream>

using namespace std;

enum status {
    NOTPLAYED = 0,
    WIN,
    DRAW,
    LOSE
};

status Ts[5][5];
int Tp[5];
int N;

bool solve(int i, int j) {
    if (i == N) {
        int p[5];
        for (int m = 0; m < N; m++) {
            p[m] = 0;
            for (int n = 0; n < N; n++) {
                if (m != n) {
                    switch (Ts[m][n]) {
                    case WIN:
                        p[m] += 3;
                        break;
                    case DRAW:
                        p[m] += 1;
                        break;
                    }
                }
            }
            if (p[m] != Tp[m]) {
                return false;
            }
        }
        return true;
    }

    if (j < N) {
        if ((i != j) && (Ts[i][j] == NOTPLAYED) && (Ts[j][i] == NOTPLAYED)) {
            Ts[i][j] = WIN;
            Ts[j][i] = LOSE;
            if (solve(i, j + 1)) {
                return true;
            }

            Ts[i][j] = LOSE;
            Ts[j][i] = WIN;
            if (solve(i, j + 1)) {
                return true;
            }

            Ts[i][j] = DRAW;
            Ts[j][i] = DRAW;
            if (solve(i, j + 1)) {
                return true;
            }

            Ts[i][j] = NOTPLAYED;
            Ts[j][i] = NOTPLAYED;
        } else {
            return solve(i, j + 1);
        }
    } else if (j == N) {
        return solve(i + 1, 0);
    }
    return false;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        memset(Ts, 0, sizeof(Ts));
        for (int i = 0; i < N; i++) {
            cin >> Tp[i];
        }

        cout << (solve(0, 0) ? "YES" : "NO") << endl;
    }

    return 0;
}

