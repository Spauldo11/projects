#include <iostream>
#include <vector>
using namespace std;
int binary_search(vector<int> arr, int start, int end, int target) {
    while (start <= end) {
        int med = start + (end - start) / 2;
    if (arr[med] == target) {
        return med;
    } else if (arr[med] < target) {
        start = med + 1;
    } else {
        end = med - 1;
    }
}
return -1;
}
int main() {
    vector<int> arr;
    for (int i = 0; i < 100; i++) {
        arr.push_back(i);
    }
    int target = 38;
    int start = 0;
    int end = arr.size() - 1;
    int result = binary_search(arr, start, end, target);
    cout << result;
}