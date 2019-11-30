#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void Transposition(vector<int> digits, int pos, vector<vector<int>> &transpositions) {
    if (pos >= digits.size()) {
        transpositions.push_back(digits);
        return;
    } else if (pos < digits.size()) {
        for (int i = pos; i < digits.size(); i++) {
            swap(digits[i], digits[pos]);
            Transposition(digits, pos + 1, transpositions);
        }
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N = 0;
    input >> N;

    vector<int> digits(N);
    vector<vector<int>> transpositions;


    for (int i = 0; i < N; i++) {
        digits[i] = 1 + i;
    }

    Transposition(digits, 0, transpositions);

    sort(transpositions.begin(), transpositions.end());

    for (int i = 0; i < transpositions.size(); i++) {
        for (int j = 0; j < N; j++) {
            output << transpositions[i][j] << " ";
        }
        output << endl;
    }
    return 0;
}