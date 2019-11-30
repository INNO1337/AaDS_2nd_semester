#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
    string fst;

    input >> fst;
    string reverced = fst;
    reverse(reverced.begin(), reverced.end());
    string str = reverced + 'U' + fst;
    int N = str.length();
    vector<int> PF (N);
    Prefix_function(PF, str);

    for (int i = PF[PF.size() - 1]; i < reverced.length(); i++) {
        output << reverced[i];
    }
    return 0;

}
