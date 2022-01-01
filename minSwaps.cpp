#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int> numbers) {
    int n = numbers.size();

    pair<int, int> old_positions[n];
    for (int i = 0; i < n; i++) {
        old_positions[i].first = numbers[i];
        old_positions[i].second = i;
    }

    sort(old_positions, old_positions+n);

    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cycle = 0;
        int node = i;
        while(!visited[node]) {
            visited[node] = true;
            node = old_positions[node].second;
            cycle++;
        }
        if (cycle > 0) ans += cycle - 1;
    }


    return ans;
}

int main(void) {
    vector<int> numbers = {2,4,5,1,3};
    cout << minSwaps(numbers) << endl;

    return 0;
}
