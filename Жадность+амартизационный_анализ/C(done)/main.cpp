#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>&i, const pair<int, int>&j) {
    return i.first > j.first;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N = 0;
    vector<pair<int,int>> array;

    input >> N;
    pair<int,int> tmp;
    for (int i = 0; i < N; i++) {
        input >> tmp.first;
        input >> tmp.second;
        array.push_back(tmp);
    }

    sort(array.begin(), array.end(), compare);

    int count = 0;
    int time = 1500;
    for (int i = 0; i < N; i++) {
        if (time >= array[i].second) {
            count++;
            time = array[i].first;
        }
    }
    output << count;

    return 0;
}