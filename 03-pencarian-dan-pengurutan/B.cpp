// B - Petak Menarik
#include <iostream>
#include <cstring>

using namespace std;

#ifdef DEBUG
#define DUMP(x) ::std::cout << #x << ": " << (x) << ::std::endl
#else
#define DUMP(x)
#endif

struct Board {
    int rows;
    int cols;
    int *data;
};

Board *Board_create(int rows, int cols) {
    Board *b = new Board;
    b->rows = rows;
    b->cols = cols;
    b->data = new int[rows * cols];
    memset(b->data, 0, rows * cols * sizeof(int));
    return b;
}

void Board_destroy(Board *b) {
    if (b != NULL) {
        delete[] b->data;
    }
    delete b;
}

bool Board_check(Board *b, int i, int j) {
    return !((i < 1) || (j < 1) || (i > b->rows) || (j > b->cols));
}

int Board_get(Board *b, int i, int j) {
    if (!Board_check(b, i, j)) {
        return 0;
    }
    i--;
    j--;
    return b->data[i * b->cols + j];
}

int Board_interest(Board *b, int i, int j) {
    if ((b->rows == 1) && (b->cols == 1)) {
        return 0; // I'm sure this wouldn't be happening :)
    }

    int top = 1;
    if (i > 1) {
        top = Board_get(b, i - 1, j);
    }

    int bottom = 1;
    if (i < b->rows) {
        bottom = Board_get(b, i + 1, j);
    }

    int left = 1;
    if (j > 1) {
        left = Board_get(b, i, j - 1);
    }

    int right = 1;
    if (j < b->cols) {
        right = Board_get(b, i, j + 1);
    }

    return top * bottom * left * right;
}

void Board_set(Board *b, int i, int j, int value) {
    if (Board_check(b, i, j)) {
        i--;
        j--;
        b->data[i * b->cols + j] = value;
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    Board *b = Board_create(N, M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int value;
            cin >> value;
            Board_set(b, i, j, value);
        }
    }

    int r = 0;
    int c = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int cur = Board_interest(b, i, j);
            DUMP(i); DUMP(j);
            DUMP(Board_interest(b, i, j));
            if (cur == K) {
                bool assign = false;
                if ((r == 0) && (c == 0)) {
                    assign = true;
                } else {
                    if (j < c) {
                        assign = true;
                    } else {
                        if (i < r) {
                            assign = true;
                        }
                    }
                }
                if (assign) {
                    r = i;
                    c = j;
                }
            }
        }
    }

    cout << r << " " << c << endl;

    Board_destroy(b);

    return 0;
}

