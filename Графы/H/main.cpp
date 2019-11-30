#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    const int MaxVert = 2000000000;
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N = 0, M = 0;
    int u, v, w;
    input >> N;
    input >> M;

    vector<vector<int>> matrix (N, vector<int>(N, MaxVert));
    for (int i = 0; i < M; i++) {
        input >> u;
        input >> v;
        input >> w;
        matrix[u - 1][v - 1] = w;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((matrix[i][k] < MaxVert) && (matrix[k][j] < MaxVert)) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                output << 0;
            } else if (matrix[i][j] != MaxVert) {
                output << matrix[i][j];
            } else {
                output << " ";
            }

            if (j < N - 1) {
                output << " ";
            }
        }
        if (i < N - 1) {
            output << "\n";
        }
    }
    return 0;
}