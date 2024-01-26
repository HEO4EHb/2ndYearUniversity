#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> buildFiniteAutomata(const string& pattern) {
    vector<vector<int>> FA(pattern.size() + 1, vector<int>(256, 0));
    int state = 0;
    FA[0][pattern[0]] = 1;
    for (int i = 1; i < pattern.size(); i++) {
        for (int ch = 0; ch < 256; ch++) {
            FA[i][ch] = FA[state][ch];
        }
        FA[i][pattern[i]] = i + 1;
        state = FA[state][pattern[i]];
    }
    for (int ch = 0; ch < 256; ch++) {
        FA[pattern.size()][ch] = FA[state][ch];
    }
    return FA;
}

void findMatches(const string& text, const string& pattern) {
    auto fsm = buildFiniteAutomata(pattern);
    int state = 0;
    for (int i = 0; i < text.size(); i++) {
        state = fsm[state][text[i]];
        if (state == pattern.size()) {
            cout << "Match found at index " << i - pattern.size() + 1 << "\n";
        }
    }
}

int main() {
    string text = "abracadabra";
    string pattern = "abra";
    findMatches(text, pattern);
    return 0;
}