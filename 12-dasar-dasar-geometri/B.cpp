// B - 5 Segmen Garis
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define DBG(_X) _X
#else
#define DBG(_X)
#endif

struct lseg {
    double x1, y1;
    double x2, y2;

    lseg(void) {
        x1 = 0.0;
        x2 = 0.0;
        y1 = 0.0;
        y2 = 0.0;
    }

    lseg(double _x1, double _y1, double _x2, double _y2) {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
};

lseg transform(const lseg &l, double x, double y) {
    lseg t;
    t.x1 = l.x1 + x;
    t.y1 = l.y1 + y;
    t.x2 = l.x2 + x;
    t.y2 = l.y2 + y;
    return t;
}

double slope(const lseg &l) {
    return (l.y2 - l.y1) / (l.x2 - l.x1);
}

double lseg_interpolate_y(const lseg &l, double x) {
    return slope(l) * (x - l.x1) + l.y1;
}

double lseg_interpolate_x(const lseg &l, double y) {
    return (y - l.y1) / slope(l) + l.x1;
}

bool lseg_intersect_x(const lseg &l, double rx0, double rx1) {
    DBG(cout << "checking X intersection in [" << x0 << ", " << x1 << "]" << endl);
    if (l.y1 * l.y2 > 0.0) {
        return false;
    }

    if ((slope(l) == INFINITY) || (slope(l) == -INFINITY)) {
        return rx0 <= l.x1 && l.x1 <= rx1;
    }

    if (slope(l) == 0.0) {
        double c1 = (rx0 + rx1) / 2.0;
        double r1 = abs(rx0 - rx1) / 2.0;
        double c2 = (l.x1 + l.x2) / 2.0;
        double r2 = abs(l.x1 - l.x2) / 2.0;
        double d = abs(c1 - c2);
        return (l.y1 == 0.0) && (d <= r1 + r2);
    }

    double x = lseg_interpolate_x(l, 0.0);
    DBG(cout << "intersection at " << x << endl);
    return rx0 <= x && x <= rx1;
}

bool lseg_intersect_y(const lseg &l, double ry0, double ry1) {
    DBG(cout << "checking Y intersection in [" << y0 << ", " << y1 << "]" << endl);
    if (l.x1 * l.x2 > 0.0) {
        return false;
    }

    if (slope(l) == 0.0) {
        return ry0 <= l.y1 && l.y1 <= ry1;
    }

    if ((slope(l) == INFINITY) || (slope(l) == -INFINITY)) {
        double c1 = (ry0 + ry1) / 2.0;
        double r1 = abs(ry0 - ry1) / 2.0;
        double c2 = (l.y1 + l.y2) / 2.0;
        double r2 = abs(l.y1 - l.y2) / 2.0;
        double d = abs(c1 - c2);
        return (l.x1 == 0.0) && (d <= r1 + r2);
    }

    double y = lseg_interpolate_y(l, 0.0);
    DBG(cout << "intersection at " << y << endl);
    return ry0 <= y && y <= ry1;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        double left = min(x1, x2);
        double right = max(x1, x2);
        double bottom = min(y1, y2);
        double top = max(y1, y2);

        bool pass = false;
        lseg l = lseg(x3, y3, x4, y4);
        lseg tr;

        // left
        tr = transform(l, -left, 0.0);
        pass = pass || lseg_intersect_y(tr, bottom, top);

        // right
        tr = transform(l, -right, 0.0);
        pass = pass || lseg_intersect_y(tr, bottom, top);

        // bottom
        tr = transform(l, 0.0, -bottom);
        pass = pass || lseg_intersect_x(tr, left, right);

        // top
        tr = transform(l, 0.0, -top);
        pass = pass || lseg_intersect_x(tr, left, right);

        cout << (pass ? "YA" : "TIDAK") << endl;
    }

    return 0;
}

