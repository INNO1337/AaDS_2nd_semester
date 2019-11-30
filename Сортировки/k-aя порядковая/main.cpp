#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//_______________________Order_______statistic__________________________________________________________________________
int Partition(vector<int> &Array, int left, int right) {
    int pivot = Array[(left + right) / 2];
    int i = left - 1;
    int j = right + 1;
    while (true) {
        do {
            i++;
        } while (Array[i] < pivot);

        do {
            j--;
        } while (Array[j] > pivot);

        if (i >= j) {
            return j;
        }
        swap(Array[i], Array[j]);
    }
}

int RandomPartition(vector<int> &Array, int left, int right) {
    int i = left + rand() % (right - left + 1);
    swap(Array[right], Array[i]);
    return Partition(Array, left, right);
}

int FindOS(vector<int> &Array, int K) {
    int left = 0;
    int right = Array.size() - 1;

    int mid = 0;
    while (true) {
        mid = RandomPartition(Array, left, right);

        if (mid == K) {
            return Array[mid];
        } else if (K < mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
}

int main() {
    srand(time(NULL));
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N = 0;
    int K = 0;
    int result = 0;

    input >> N;
    vector<int> Array(N);
    input >> K;
    K--;

    for (int i = 0; i < N; i++) {
        input >> Array[i];
    }

    result = FindOS(Array, K);

    output << result;

    return 0;
}