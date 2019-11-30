#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct shu {
    string answer;
    int points;
};

void rec (int pos, const int p, int q, vector<char> signs, vector<shu> &test, string &res, string str) {
    int count = 0;
    if (pos >= q) {
        for (int i = 0; i < p; i++) {
            count = 0;

            for (int j = 0; j < q; j++) {
                if (test[i].answer[j] == str[j])
                    count++;
            }
            if (count != test[i].points)
                break;
            if (i == p - 1) {
                res = str;
                return;
            }
        }
        return;
    }
    char c = ' ';
    for (auto i: signs) {
        c = i;
        rec(pos + 1, p, q, signs, test, res, (str + c));
    }
}

int main () {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int P, Q;
    vector<char> signs = {'-', '+'};
    string result;
    input >> P >> Q;
    vector<shu> test(P);

    for (auto &i: test) {
        input >> i.answer >> i.points;
    }

    rec( 0, P, Q, signs, test, result, "");
    output << result;
}

