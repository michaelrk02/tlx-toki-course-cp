// F - Pesta Bebek
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifdef DEBUG
#define DUMP(x) ::std::cout << #x << ": " << (x) << ::std::endl
#else
#define DUMP(x)
#endif

int findInsertionPosEx(const vector<string> &data, const string &item, int left, int right) {
    if (data.size() == 0) {
        return 0;
    }

    int middle = (left + right) / 2;
    int cmp = item.compare(data[middle]);
    if (left >= right) {
        if (cmp < 0) {
            return middle;
        } else if (cmp > 0) {
            return middle + 1;
        }
    }
    if (cmp < 0) {
        return findInsertionPosEx(data, item, 0, middle - 1);
    } else if (cmp > 0) {
        return findInsertionPosEx(data, item, middle + 1, right);
    }
    return middle;
}

int findInsertionPos(const vector<string> &data, const string &item) {
    return findInsertionPosEx(data, item, 0, data.size() - 1);
}

int main() {
    int N;
    cin >> N;

    vector<string> data;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        int pos = findInsertionPos(data, name);
        data.insert(data.begin() + pos, name);
        cout << (pos + 1) << endl;
    }

    return 0;
}

