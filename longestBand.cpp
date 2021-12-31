#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findLongestBand(vector<int> &numbers) {
    unordered_set<int> numbers_set;
    for (auto element: numbers) {
        numbers_set.insert(element);
    }

    int length = 0;
    for (auto current: numbers) {
        int previous = current - 1;
        if (numbers_set.find(previous) != numbers_set.end()) {
            continue;
        }
        else {
            int next = current + 1;
            int cnt = 1;
            while (numbers_set.find(next) != numbers_set.end()) {
                cnt++;
                next++;
            }
            length = max(length, cnt);
        }

    }

    return length;
}

int main(void) {
    vector<int> numbers = {1,9,3,0,18,5,2,4,10,7,12,6};

    cout << findLongestBand(numbers) << endl;

    return 0;
}
