#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N, M, S = 0;
    int a, b, w;
    int inf = 5000;
    input >> N;
    input >> M;
    input >> S;

    vector<vector<int>> Graphs(N, vector<int>(N));
    vector<int> visited(N);
    vector<int> arr(N, inf);

    for (int i = 0; i < M; i++) {
        input >> a >> b >> w;
        Graphs[a-1][b - 1] = w;
    }
    arr[S - 1] = 0;

    for (int i = 0; i < N; i++) {
        int V = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && ((V == -1) || arr[j] < arr[V])) {
                V = j;
            }
        }
        if (arr[V] == inf) {
            break;
        }
        visited[V] = 1;
        for (int j = 0; j < N; j++) {
            if (Graphs[V][j] > 0 && arr[j] > (arr[V] + Graphs[V][j])) {
                arr[j] = arr[V] + Graphs[V][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] == inf) {
            output << -1 << " ";
        } else {
            output << arr[i] << " ";
        }
    }




    return 0;
}