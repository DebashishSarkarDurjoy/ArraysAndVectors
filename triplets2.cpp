#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> findTriplets(vector<int> numbers, int targetSum) {
    vector<vector<int>> result;
    int n = numbers.size();

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < n - 3; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = numbers[i] + numbers[j] + numbers[k];

            if (sum == targetSum) {
                result.push_back({numbers[i], numbers[j], numbers[k]});
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

    return result;
}

void showTriplets(vector<vector<int>> numbers) {
    for (vector<int> num_vec: numbers) {
        for (int num: num_vec) {
            cout << num << ", ";
        }
        cout << endl;
    }
}

int main(void) {
    vector<int> points = {1,2,3,4,5,6,7,8,9,15};
    showTriplets(findTriplets(points, 18));

    return 0;
}
