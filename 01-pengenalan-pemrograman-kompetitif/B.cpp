// B - Runtuh
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#ifdef DEBUG
#define DUMP(x) ::std::cout << #x << ": " << (x) << ::std::endl
#else
#define DUMP(x)
#endif

typedef struct _board_t {
    bool *cells;
    int r, c;
} *board_t;

board_t bcreate(int r, int c) {
    board_t b = new _board_t;
    b->cells = new bool[r * c];
    memset(b->cells, 0, sizeof(bool) * r * c);
    b->r = r;
    b->c = c;
    return b;
}

void bdestroy(board_t b) {
    delete[] b->cells;
    delete b;
}

bool bget(board_t b, int i, int j) {
    return b->cells[i * b->c + j];
}

void bset(board_t b, int i, int j, bool val) {
    b->cells[i * b->c + j] = val;
}

int delete_full_rows(board_t b) {
    int bottom = -1;
    for (int i = 0; i < b->r; i++) {
        bool full = true;
        for (int j = 0; j < b->c; j++) {
            DUMP(i);
            if (!bget(b, i, j)) {
                full = false;
                break;
            }
        }
        if (full) {
            for (int j = 0; j < b->c; j++) {
                bset(b, i, j, false);
            }
            bottom = i;
        }
    }
    return bottom;
}

void collapse(board_t b, int bottom) {
    for (int j = 0; j < b->c; j++) {
        int base = bottom;
        for (int i = base + 1; i < b->r; i++) {
            if (!bget(b, i, j)) {
                base = i;
            } else {
                break;
            }
        }
        for (int i = base - 1; i >= 0; i--) {
            if (bget(b, i, j)) {
                bset(b, i, j, false);
                bset(b, base--, j, true);
            }
        }
    }
}

int main() {
    int R, C;
    cin >> R >> C;

    board_t b = bcreate(R, C);
    for (int i = 0; i < b->r; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {
            bset(b, i, j, str[j] == '1');
        }
    }

#ifdef DEBUG
    for (int i = 0; i < b->r; i++) {
        for (int j = 0; j < b->c; j++) {
            cout << bget(b, i, j);
        }
        cout << endl;
    }
#endif

    int bottom;
    while ((bottom = delete_full_rows(b)) != -1) {
        collapse(b, bottom);
    }

    for (int i = 0; i < b->r; i++) {
        for (int j = 0; j < b->c; j++) {
            cout << bget(b, i, j);
        }
        cout << endl;
    }

    bdestroy(b);

    return 0;
}
