#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class arc {
public:
    int u = 0;
    int v = 0;
    int w = 0;
private:
};

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    const int MaxVert = 5000;
    int N, M, S, u, v, w;
    input >> N;
    input >> M;
    input >> S;
    vector<arc> arc(M);
    vector<int> result(N, MaxVert);

    result[S - 1] = 0;

    for (int i = 0; i < M; i++) {
        input >> u;
        input >> v;
        input >> w;
        arc[i].u = u - 1;
        arc[i].v = v - 1;
        arc[i].w = w;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            if (result[arc[j].u] < MaxVert) {
                result[arc[j].v] = min(result[arc[j].v], result[arc[j].u] + arc[j].w);
            }
        }
    }

    for (int i: result) {
        if (i != MaxVert) {
            output << i << " ";
        } else
            output << "  ";
    }

    return 0;
}
