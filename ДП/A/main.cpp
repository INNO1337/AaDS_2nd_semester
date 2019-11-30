#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string fst_line;
    string scnd_line;
    string result;
    int fst_size, scnd_size = 0;

    getline(input, fst_line);
    getline(input, scnd_line);

    fst_size = fst_line.size();
    scnd_size = scnd_line.size();

    vector<vector<int>> LCS(fst_line.size() + 1);
    vector<int> tmp(scnd_line.size() + 1);

    for (int i = 0; i < fst_line.size() + 1; i++) {
        LCS[i] = tmp;
    }

    for (int i = 1; i < fst_line.size() + 1; ++i) {
        for (int j = 1; j < scnd_line.size() + 1; ++j) {
            if (fst_line[i - 1] == scnd_line[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    while (fst_size > 0 && scnd_size > 0) {
        if (LCS[fst_size - 1][scnd_size] == LCS[fst_size][scnd_size]) {
            fst_size--;
        } else if (fst_line[fst_size - 1] == scnd_line[scnd_size - 1]) {
            result = fst_line[fst_size - 1] + result;
            fst_size--; scnd_size--;
        } else {
            scnd_size--;
        }
    }

    output << result;
    return 0;
}