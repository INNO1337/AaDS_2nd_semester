#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    string line;
    int result = 0;
    getline(input, line);


    long long int N = line.size();
    vector<int> PF (N);

    for (int i = 1; i < N; i++) {
        int j = PF[i - 1];
        while (j > 0 && (line[i] != line[j])) {
            j = PF[j - 1];
        }
        if (line[i] == line[j]) {
            j++;
        }
        PF[i] = j;
    }


    for (int i: PF) {
        result += i;
    }

    output << result;
    return 0;
}