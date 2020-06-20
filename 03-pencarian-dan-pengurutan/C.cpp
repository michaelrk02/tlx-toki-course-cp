// C - Wartel
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Address {
    string name;
    string phoneNumber;
};

int findAddress(const vector<Address> &book, const string &name, int left, int right) {
    if ((left >= right) && (book[left].name != name)) {
        return -1;
    }

    int middle = (left + right) / 2;
    int diff = name.compare(book[middle].name);
    if (diff < 0) {
        return findAddress(book, name, 0, middle - 1);
    } else if (diff > 0) {
        return findAddress(book, name, middle + 1, right);
    }
    return middle;
}

string findPhoneNumber(const vector<Address> &book, const string &name) {
    int index = findAddress(book, name, 0, book.size() - 1);
    if (index == -1) {
        return "NIHIL";
    }
    return book[index].phoneNumber;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<Address> book(N);
    for (int i = 0; i < N; i++) {
        cin >> book[i].name >> book[i].phoneNumber;
    }

    for (int i = 0; i < Q; i++) {
        string query;
        cin >> query;
        cout << findPhoneNumber(book, query) << endl;
    }

    return 0;
}
