
#include <vector>
using namespace std;

class Solution {
    
public:
    int minProductSum(vector<int>& inputFirst, vector<int>& inputSecond) {
        sort(inputFirst.begin(), inputFirst.end());
        sort(inputSecond.begin(), inputSecond.end());
        const size_t size = inputFirst.size();
        int minProductSum = 0;
        for (int i = 0; i < size; i++) {
            minProductSum += inputFirst[i] * inputSecond[size - i - 1];
        }
        return minProductSum;
    }
};
