#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int Q[25][25], Qc[25][25];
int M, N;

int solve(int i, int j, int c) {
    int T = 0;

    Q[i][j] = 0;
    T++;

    if ((i > 0) && (Q[i - 1][j] == c)) {
        T += solve(i - 1, j, c);
    }
    if ((i < M - 1) && (Q[i + 1][j] == c)) {
        T += solve(i + 1, j, c);
    }
    if ((j > 0) && (Q[i][j - 1] == c)) {
        T += solve(i, j - 1, c);
    }
    if ((j < N - 1) && (Q[i][j + 1] == c)) {
        T += solve(i, j + 1, c);
    }

    return T;
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Q[i][j];
            Qc[i][j] = Q[i][j];
        }
    }

    int maximum = 0;
    int B = 0;
    int K = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (Q[i][j] != 0) {
                int T = solve(i, j, Q[i][j]);
                int score = T * (T - 1);
                if (score > maximum) {
                    B = i;
                    K = j;
                    maximum = score;
                }
            }
        }
    }

    memcpy(Q, Qc, sizeof(Q));
    solve(B, K, Q[B][K]);

    for (int i = M - 2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (Q[i][j] != 0) {
                int k = i;
                while ((k < M - 1) && (Q[k + 1][j] == 0)) {
                    Q[k + 1][j] = Q[k][j];
                    Q[k][j] = 0;
                    k++;
                }
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (Q[i][j] == 0) {
                cout << '.';
            } else {
                cout << Q[i][j];
            }
            if (j == N - 1) {
                cout << endl;
            } else {
                cout << ' ';
            }
        }
    }

    return 0;
}

