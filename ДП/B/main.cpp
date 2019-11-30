#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 10000


int Min(vector<int> Array) {
    sort(Array.begin(), Array.end());
    return Array[0];
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int E, F, N;
    input >> E;
    input >> F;
    input >> N;
    int W = F - E;
    vector<pair<int, int>> coins;

    pair<int, int> pair_tmp; //first C, second W;

    vector<int> swin(W+1, MAX);

    swin[0] = 0;
    for (int i = 1; i < N + 1; i++) {
        input >> pair_tmp.first;
        input >> pair_tmp.second;
        for (int j = 0; j < W + 1; j++) {
            if (j >= pair_tmp.second) {
                if (swin[j] < (swin[j - pair_tmp.second] + pair_tmp.first)) {
                    swin[j] = swin[j];
                } else {
                    swin[j] = swin[j - pair_tmp.second] + pair_tmp.first;
                }
            }
        }
    }

    if (swin[W] == MAX) {
        output << -1;
    } else {
        output << swin[W];
    }
    return 0;
}