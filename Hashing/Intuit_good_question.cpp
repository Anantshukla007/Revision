/*Given an integer kand a list of integers, count the number of distinct valid pairs of integers (a, b) in the list for which a + k = b. Two pairs of integers (a, b) and (c, d) are considered distinct if at least one element of (a, b) does not also belong to (c, d). Note that the elements in a pair might be the same element in the array. An instance of this is below where k = 0.
Example
n=4
numbers = [1, 1, 1, 2] k=1
This array has three different valid pairs: (1, 1) and (1, 2) and (2, 2). For k = 1, there is only 1 valid pair which satisfies a + k = b. the pair (a, b) = (1, 2).*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countValidPairs(const vector<int>& numbers, int k) {
    unordered_set<int> seen;
    unordered_set<int> uniqueA;

    for (int num : numbers) {
        seen.insert(num);
    }

    int count = 0;
    for (int num : numbers) {
        if (seen.count(num + k) && !uniqueA.count(num)) {
            count++;
            uniqueA.insert(num);
        }
    }

    return count;
}

int main() {
    vector<int> numbers = {1, 1, 1, 2};
    int k = 1;
    int result = countValidPairs(numbers, k);
    cout << "Number of distinct valid pairs: " << result << endl;
    return 0;
}
