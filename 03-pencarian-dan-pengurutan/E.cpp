// E - Pertemuan Pak Dengklek
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> data[10];
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        data[name.size() - 1].push_back(name);
    }
    for (int i = 0; i < 10; i++) {
        if (data[i].size() > 0) {
            sort(data[i].begin(), data[i].end());
            for (int j = 0; j < data[i].size(); j++) {
                cout << data[i][j] << endl;
            }
        }
    }

    return 0;
}
