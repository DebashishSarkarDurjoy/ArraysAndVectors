#include <iostream>
#include <vector>
using namespace std;

bool outOfOrder(vector<int> arr, int i) {
    if (i == 0) {
        return arr[i] > arr[i+1];
    }
    if (i == arr.size() - 1) {
        return arr[i] < arr[i-1];
    }
    return arr[i] > arr[i+1]  ||  arr[i] < arr[i-1];
}

pair<int, int> subarraySort(vector<int> &arr) {
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if ( outOfOrder(arr, i) ) {
            smallest = min(smallest, arr[i]);
            largest = max(largest, arr[i]);
        }
    }

    int first = 0;
    while (smallest > arr[first]) first++;

    int second = arr.size() - 1;
    while (largest < arr[second]) second--;

    return {first, second};
}

int main(void) {
    vector<int> numbers = {1,2,3,4,5,8,6,7,9,10,11};
    pair<int, int> result = subarraySort(numbers);
    cout << result.first << " " << result.second << endl;

    return 0;
}
