#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
using namespace std;

void Way_found (vector<vector<pair<int, int>>> &last, queue<pair<int, int>> &Q, vector<vector<char>> &labirinth, int first, int second, pair<int, int> &coordinate) {
    pair<int, int> pair_tmp;
    last[first][second] = coordinate;
    pair_tmp.first = first;
    pair_tmp.second = second;
    Q.push(pair_tmp);
    labirinth[first][second] = 'w';
}

void Search_for_a_way(int &N, int &x, int &y, vector<vector<char>> &labyrinth, queue<pair<int, int>> &Q, pair<int, int> &coords, vector<vector<pair<int, int>>> &last) {
    if (x > 0 && labyrinth[x - 1][y] == '.') {
        Way_found(last, Q, labyrinth, x - 1, y, coords);
    }

    if (x < N - 1 && labyrinth[x + 1][y] == '.') {
        Way_found(last, Q, labyrinth, x + 1, y, coords);
    }

    if (y > 0 && labyrinth[x][y - 1] == '.') {
        Way_found(last, Q, labyrinth, x, y - 1, coords);
    }

    if (y < N - 1 && labyrinth[x][y + 1] == '.') {
        Way_found(last, Q, labyrinth, x, y + 1, coords);
    }
}

void Cast_to_convenient_count(pair<int, int> &start, pair<int, int> &finish) {
    start.first--; start.second--;
    finish.first--; finish.second--;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N, x, y = 0;
    int path = 0;
    input >> N;
    pair<int, int> start, finish, coords;
    vector<vector<char>> labyrinth(N);
    vector<vector<pair<int, int>>> last(N);
    queue<pair<int, int>> Q;

    input >> start.second;
    input >> start.first;
    input >> finish.first;
    input >> finish.second;

    for (int i = 0; i < N; i++) {
        labyrinth[i].resize(N);
        last[i].resize(N);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            input >> labyrinth[i][j];
        }
    }

    Cast_to_convenient_count(start, finish);

    labyrinth[start.first][start.second] = 'w';
    coords.first = start.first;
    coords.second = start.second;
    Q.push(coords);

    while (!Q.empty()) {
        coords = Q.front();
        x = coords.first;
        y = coords.second;
        Q.pop();

        if (coords.first == finish.second && coords.second == finish.first) {
            break;
        }

        Search_for_a_way(N, x, y, labyrinth, Q, coords, last);
    }

    while (coords.first != start.first || coords.second != start.second) {
        coords = last[coords.first][coords.second];
        path++;
    }
    output << path;

    return 0;
}

