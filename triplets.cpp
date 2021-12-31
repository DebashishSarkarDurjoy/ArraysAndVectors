#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findTriplets(vector<int> points, int targetSum) {
    int n = points.size();
    vector<vector<int>> result;

    sort(points.begin(), points.end());

    for (int i = 0; i <= n - 3; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = points[i] + points[j] + points[k];

            if (sum == targetSum) {
                result.push_back({points[i], points[j], points[k]});
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
    for (vector<int> number_vec: numbers) {
        for (int num: number_vec) {
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
