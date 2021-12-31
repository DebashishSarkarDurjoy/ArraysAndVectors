#include <iostream>
#include <vector>

using namespace std;

int findMountainLength(vector<int> numbers) {
    int length = 0;
    int n = numbers.size();

    for (int i = 1; i <= n - 2; ) {
        if ( (numbers[i-1] < numbers[i]) && (numbers[i+1] < numbers[i]) ) {
            int j = i;
            int count = 1;
            while ( (j >= 1) && (numbers[j-1] < numbers[j]) ) {
                j--;
                count++;
            }
            while ( (i <= n - 2) && (numbers[i+1] < numbers[i]) ) {
                i++;
                count++;
            }
            length = max(length, count);
        }
        else i++;
    }

    return length;
}

int main(void) {
    vector<int> numbers = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout << findMountainLength(numbers) << endl;

    return 0;
}
