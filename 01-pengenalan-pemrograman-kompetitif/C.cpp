// C - Wildcard
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifdef DEBUG
#define DUMP(x) ::std::cout << #x << ": " << (x) << ::std::endl
#else
#define DUMP(x)
#endif

struct state_t {
    map<char, int> trans;
};

struct automata_t {
    vector<state_t> states;
    int cur, end;
};

void automata_feed(automata_t *aut, char ch) {
    state_t &q = aut->states[aut->cur];
    map<char, int>::iterator it = q.trans.find(ch);
    if (it == q.trans.end()) {
        aut->cur = q.trans['*'];
    } else {
        aut->cur = q.trans[ch];
    }
}

bool matches(const string &pattern, const string &subject) {
    automata_t aut;

    aut.states.resize(pattern.size() + 2);
    aut.states[0].trans['*'] = 0;
    aut.states[1].trans['*'] = 0;

    aut.end = aut.states.size() - 1;

    int fallback = 0;
    for (int i = 0; i < pattern.size(); i++) {
        int n = i + 2;

        if (pattern[i] == '*') {
            fallback = n;
            aut.states[n - 1].trans['*'] = n;
            if (i + 1 < pattern.size()) {
                char follow = pattern[i + 1];
                int dupl_end = i;
                aut.states[n - 1].trans[pattern[i + 1]] = n + 1;
                for (int j = i + 1; j < pattern.size(); j++) {
                    if (pattern[j] == follow) {
                        dupl_end++;
                    } else {
                        follow = '\0';
                    }
                    if (j + 1 < pattern.size()) {
                        if (pattern[j + 1] == '*') {
                            break;
                        }
                    }
                    aut.states[j + 2].trans[pattern[i + 1]] = n + 1;
                }
                aut.states[dupl_end + 2].trans[pattern[i + 1]] = dupl_end + 2;
            }
        } else {
            aut.states[n - 1].trans[pattern[i]] = n;
        }
        aut.states[n].trans['*'] = fallback;
    }
    aut.states[aut.end].trans['\0'] = aut.end;
    aut.cur = 1;

    for (int i = 0; i < subject.size(); i++) {
        automata_feed(&aut, subject[i]);
        DUMP(aut.cur);
    }
    automata_feed(&aut, '\0');

    return aut.cur == aut.end;
}

int main() {
    string raw_pattern;
    cin >> raw_pattern;

    ostringstream oss;
    char ch = '\0';
    for (int i = 0; i < raw_pattern.size(); i++) {
        if (raw_pattern[i] != '*') {
            ch = raw_pattern[i];
            oss << ch;
        } else {
            if (ch != '*') {
                ch = '*';
                oss << ch;
            }
        }
    }

    string pattern = oss.str();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string subject;
        cin >> subject;

        if (matches(pattern, subject)) {
            cout << subject << endl;
        }
    }

    return 0;
}

// For those who didn't solve this problem with the help from finite-state automata,
//  YOU GUYS ARE REALLY COOL B-)
