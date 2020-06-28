// A - Refleksi Matriks
#include <iostream>

using namespace std;

struct Matrix {
    int dim;
    int *data;
};

Matrix *Matrix_create(int dim) {
    Matrix *m = new Matrix;
    m->dim = dim;
    m->data = new int[dim * dim];
    return m;
}

int Matrix_get(Matrix *m, int r, int c) {
    return m->data[r * m->dim + c];
}

void Matrix_set(Matrix *m, int r, int c, int value) {
    m->data[r * m->dim + c] = value;
}

void Matrix_destroy(Matrix *m) {
    delete[] m->data;
    delete m;
}

bool check_similarity(Matrix *a, Matrix *b) {
    if (a->dim != b->dim) {
        return false;
    }

    for (int i = 0; i < a->dim; i++) {
        for (int j = 0; j < a->dim; j++) {
            if (Matrix_get(a, i, j) != Matrix_get(b, i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool check_horizontal(Matrix *a, Matrix *b) {
    if (a->dim != b->dim) {
        return false;
    }

    for (int i = 0; i < a->dim; i++) {
        for (int j = 0; j < a->dim; j++) {
            if (Matrix_get(a, i, j) != Matrix_get(b, a->dim - 1 - i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool check_vertical(Matrix *a, Matrix *b) {
    if (a->dim != b->dim) {
        return false;
    }

    for (int i = 0; i < a->dim; i++) {
        for (int j = 0; j < a->dim; j++) {
            if (Matrix_get(a, i, j) != Matrix_get(b, i, a->dim - 1 - j)) {
                return false;
            }
        }
    }
    return true;
}

bool check_lower_right_diagonal(Matrix *a, Matrix *b) {
    if (a->dim != b->dim) {
        return false;
    }

    for (int i = 0; i < a->dim; i++) {
        for (int j = 0; j < a->dim; j++) {
            if (Matrix_get(a, i, j) != Matrix_get(b, j, i)) {
                return false;
            }
        }
    }
    return true;
}

bool check_lower_left_diagonal(Matrix *a, Matrix *b) {
    if (a->dim != b->dim) {
        return false;
    }

    for (int i = 0; i < a->dim; i++) {
        for (int j = 0; j < a->dim; j++) {
            if (Matrix_get(a, i, j) != Matrix_get(b, a->dim - 1 - j,  a->dim - 1 - i)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N >> N;

    Matrix *a = Matrix_create(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v;
            cin >> v;
            Matrix_set(a, i, j, v);
        }
    }

    cin >> N >> N;

    Matrix *b = Matrix_create(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v;
            cin >> v;
            Matrix_set(b, i, j, v);
        }
    }

    if (check_similarity(a, b)) {
        cout << "identik" << endl;
    } else if (check_horizontal(a, b)) {
        cout << "horisontal" << endl;
    } else if (check_vertical(a, b)) {
        cout << "vertikal" << endl;
    } else if (check_lower_right_diagonal(a, b)) {
        cout << "diagonal kanan bawah" << endl;
    } else if (check_lower_left_diagonal(a, b)) {
        cout << "diagonal kiri bawah" << endl;
    } else {
        cout << "tidak identik" << endl;
    }

    Matrix_destroy(b);
    Matrix_destroy(a);

    return 0;
}
