// A - Kupon Berhadiah
#include <iostream>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int main() {
    int N, X;
    cin >> N >> X;

    int winner = 0;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        int d = ABS(K - X);
        if (i > 0) {
            int winnerDist = ABS(winner - X);
            if (d < winnerDist) {
                winner = K;
            } else if (d == winnerDist) {
                winner = MIN(K, winner);
            }
        } else {
            winner = K;
        }
    }

    cout << winner << endl;

    return 0;
}
