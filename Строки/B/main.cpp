#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Prefix_function(vector<int> &PF, string &str) {
    int N = PF.size();
    for (int i = 1; i < N; ++i) {
        int j = PF[i - 1];
        while (j > 0 && str[i] != str[j])
            j = PF[j - 1];
        if (str[i] == str[j])
            j++;
        PF[i] = j;
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    string fst, scnd;
    getline(input, scnd);
    getline(input, fst);

    int N = fst.length();
    vector<int> PF(N);
    int position = -1;
    int j = 0;

    Prefix_function(PF, fst);

    for (int i = 0; i < scnd.length(); ++i) {
        while (j > 0 && fst[j] != scnd[i])
            j = PF[j - 1];
        if (fst[j] == scnd[i])
            j++;
        if(j == fst.length()) {
            position = (i - j) + 2;
            break;
        }
    }

    output << position;
    return 0;
}
