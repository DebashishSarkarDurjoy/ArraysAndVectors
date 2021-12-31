#include <iostream>
#include <vector>

using namespace std;

int findLongestMountain(vector<int> &numbers) {
    int length = 0;
    int n = numbers.size();

    for (int i = 1; i <= n-2; ) {
        if ( (numbers[i] > numbers[i-1]) && (numbers[i] > numbers[i+1]) ) {
            int newLength = 1;
            int j = i;
            while ( (j >= 1) && (numbers[j] > numbers[j-1]) ) {
                newLength++;
                j--;
            }
            while ( (i <= n-2) && (numbers[i] > numbers[i+1]) ) {
                newLength++;
                i++;
            }
            length = max(newLength, length);
        }
        else {
            i++;
        }
    }

    return length;
}

int main(void) {
    vector<int> numbers = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout << findLongestMountain(numbers) << endl;


    return 0;
}
