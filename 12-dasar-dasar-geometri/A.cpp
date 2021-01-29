// A - Dua Gelang
#include <cmath>
#include <iostream>

using namespace std;

struct vector {
    double x, y;
};

vector vsub(const vector &l, const vector &r) {
    vector v;
    v.x = l.x - r.x;
    v.y = l.y - r.y;
    return v;
}

double vlen(const vector &v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

struct circle {
    vector c;
    double r;
};

bool touches(const circle &c1, const circle &c2) {
    vector v = vsub(c1.c, c2.c);
    double len = vlen(v);
    return (len <= c1.r + c2.r) && (len >= abs(c1.r - c2.r));
}

int main() {
    circle c1, c2;
    cin >> c1.c.x >> c1.c.y >> c1.r;
    cin >> c2.c.x >> c2.c.y >> c2.r;
    cout << (touches(c1, c2) ? "bersentuhan" : "tidak bersentuhan") << endl;
    return 0;
}

