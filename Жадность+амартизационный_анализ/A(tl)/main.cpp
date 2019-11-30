#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//_________________________Close-in_Num____________________________________________//

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N = 0;
    input >> N;
    vector<int> index(N + 1), seq(N + 1), res(N + 1);
    for (int i = 0; i < N; i++) {
        input >> seq[i];
    }

    int j = 0;
    index[0]= 0;
    for (int i = 0; i < N; i++) {
        while ((j >= 0) && seq[i + 1] > seq[index[j]])  {
            res[index[j]] = seq[i + 1];
            j--;
        }
        j++;
        index[j] = i + 1;
    }

    for (int i = 0; i < j; i++) {
        res[index[i]] = seq[index[i]];
    }

    for (int i = 0; i < N; i++) {
        output << res[i] << " ";
    }

    return 0;
}