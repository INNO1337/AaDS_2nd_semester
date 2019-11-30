#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 0;
    int M = 0;
    int left_cnt = 0;
    int right_cnt = 1; //fixed
    int head = 0;
    int tail = 0;


    char symbol = ' ';
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> N;
    int tmp = 0;
    vector<int> array;
    vector<pair<int,int>> p_array(N);

    for (int i = 0; i < N; i++) {
        input >> tmp;
        array.push_back(tmp);
    }

    input >> M;

    p_array[tail].first = array[0];
    p_array[tail].second = right_cnt;
    tail++;

    for (int i = 0; i < M; i++) {
        input >> symbol;
        if (symbol == 'R') {
            right_cnt++;
            while ((head != tail) && (p_array[tail - 1].first < array[right_cnt - 1])) {
                    tail--;
            }
            p_array[tail].first = array[right_cnt - 1];
            p_array[tail].second = right_cnt;
            tail++;
        } else {
            left_cnt++;
            if ((p_array[head].second == left_cnt) && (head + 1 < tail)) {
                head++;
            }
        }
        output << p_array[head].first << " ";
    }
    return 0;
}