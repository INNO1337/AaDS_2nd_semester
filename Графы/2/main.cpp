#include <iostream>
#include <fstream>
#include <vector>

using namespace std;





void DFS(int vert, vector<int> &color, vector<vector<int>> &Graph, int &count, vector<int> &result) {
    color[vert] = 1;
    int child = 0;
    for (int i = 0; i < Graph[vert].size() ; i++){
        child = Graph[vert][i];
        if (color[child] == 1) {
            count++;
            return;
        }
        if (color[child] == 0)
            DFS(child, color, Graph, count, result);
    }
    if (count > 0){
        return;
    }
    color[vert] = 2;
    result.push_back(vert + 1);
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N, M = 0;
    int a, b, count = 0;
    input >> N;
    vector<vector<int>> Graph(N);
    vector<int> color(N);
    vector<int> result;
    input >> M;



    for(int i = 0; i < M; i++) {
        input >> a;
        input >> b;
        Graph[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < N; i++) {
        if (color[i] == 0)
            DFS(i, color, Graph, count , result);
    }

    int size = result.size();

    if (size != N){
        output << -1;
        return 0;
    }

    for (int i = size - 1; i >= 0; i--) {
        output << result[i] << " ";
    }

    return 0;
}
