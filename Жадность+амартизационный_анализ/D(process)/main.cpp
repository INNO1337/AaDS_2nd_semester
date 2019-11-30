#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N = 0;
    input >> N;

    vector<int> band;
    set<int> bad_nums;
    set<int> nums_found;

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        input >> tmp;
        band.push_back(tmp);
    }



    int M = 0;
    input >> M;
    for (int i = 0; i < M; i++) {
        input >> tmp;
        bad_nums.insert(tmp);
    }
    int cut_cnt = 0;
    for (int i = 0; i < N; i++) {
        if (bad_nums.count(band[i]) != 0) {
            nums_found.insert(band[i]);
            if(nums_found.size() >= M) {
                nums_found.clear();
                nums_found.insert(band[i]);
                cut_cnt++;
            }
        }
    }
    output << cut_cnt;
    return 0;
}