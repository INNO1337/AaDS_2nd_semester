#include <vector>
#include <fstream>
using namespace std;



void DFS(int vert, vector<vector<int>> &Graphs, vector<bool> &visited) {
    visited[vert] = true;
    int child = 0;
    for (int i = 0; i < Graphs[vert].size() ; i++){
        child = Graphs[vert][i];
        if (!(visited[child]))
            DFS(child, Graphs, visited);
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    vector<vector<int>> Graphs(100001);
    int N, M, a, b, count = 0;
    input >> N;
    vector<bool> visited(N, false);
    input >> M;
    for(int i = 0; i < M; i++) {
        input >> a;
        input >> b;
        Graphs[a - 1].push_back(b - 1);
        Graphs[b - 1].push_back(a - 1);
    }
    int i = 0;
    while (i < N) {
        if(!visited[i]) {
            count++;
            DFS(i, Graphs, visited);
        }
        i++;
    }

    output << count;
}