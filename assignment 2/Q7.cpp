#include <iostream>
using namespace std;

int countInversions(int arr[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    cout << "Inversions: " << countInversions(arr, n);
}
