#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findTriplets(vector<int> &numbers, int targetSum) {
    vector<vector<int>> results;
    int n = numbers.size();


    for (int i = 0; i <= n-3; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = numbers[i] + numbers[j] + numbers[k];
            if (sum == targetSum) {
                results.push_back({numbers[i], numbers[j], numbers[k]});
                break;
            }
            else if (sum < targetSum) {
                j++;
            }
            else if (sum > targetSum) {
                k--;
            }
        }
    }


    return results;
}

void showTriplets(vector<vector<int>> result) {
    for (auto num_vec: result) {
        for (auto num: num_vec) {
            cout << num << ", ";
        }
        cout << endl;
    }
}

int main(void) {
    vector<int> numbers = {1,2,3,4,5,6,7,8,9,15};
    showTriplets(findTriplets(numbers, 18));


    return 0;
}
