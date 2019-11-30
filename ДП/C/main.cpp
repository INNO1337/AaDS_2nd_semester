#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int BS(const vector<int> arr, int n) {
    int l = -1;
    int r = arr.size();
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (arr[m] < n) {
            l = m;
        } else r = m;
    }
    return r;
}

void getLISLength(const vector<int>& arr, vector<int>& pos, vector<int>& prev, int &length) {
    pos[0] = -1;
    int j = 0;
    vector<int> d(arr.size() + 1);
    d[0] = -2000000000;
    for (int i = 1; i < d.size(); i++) {
        d[i] = 2000000000;
    }
    for (int i = 0; i < d.size() - 1; i++) {
        j = BS(d, arr[i]);
        if ((d[j - 1] < arr[i]) && (arr[i] < d[j])) {
            d[j] = arr[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            if (length < j)
                length = j;
        }
    }
}

void getLIS(vector<int>& pos, vector<int>& prev, int LISLength, vector<int> &answer) {
    int i = pos[LISLength];
    while (i != -1) {
        answer.push_back(i + 1);
        i = prev[i];
    }
    reverse(answer.begin(), answer.end());
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N;
    input >> N;
    vector<int> seq(N);
    vector<int> ans(N + 1);
    vector<int> prev(N + 1);
    vector<int> answer;
    int LISLength = 0;

    for(int i = 0; i < N; i++) {
        input >> seq[i];
    }

    getLISLength(seq, ans, prev, LISLength);
    getLIS(ans, prev, LISLength, answer);
    output << LISLength;
    output << endl;
    for (int i = 0; i < answer.size(); i++) {
        output << answer[i] << " ";
    }
    return 0;
}