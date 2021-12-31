#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// brute force O(n^2) algorithm
pair<int, int> findPairBruteForce(vector<int> &numbers, int target) {

    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == target) {
                return {numbers[i], numbers[j]};
                break;
            }
        }
    }
    return {-1, -1};
}

// optimised O(n) algorithm
pair<int, int> findPairOptimised(vector<int> &numbers, int target) {

    unordered_set<int> numbers_set;
    for (int n: numbers) {
        if (numbers_set.find(target-n) != numbers_set.end()) {
            return {n, target-n};
        }
        else {
            numbers_set.insert(n);
        }
    }

    return {-1,-1};
}

int main(void) {
    vector<int> numbers = {10, 5, 2, 3, -6, 9, 11};

    pair<int, int> ans = findPairOptimised(numbers, 4);
    cout << "[" << ans.first << ", " << ans.second << "]" << endl;

    return 0;
}
