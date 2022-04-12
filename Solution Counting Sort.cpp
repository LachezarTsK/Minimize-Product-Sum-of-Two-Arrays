
#include <array>
#include <vector>
using namespace std;

class Solution {
    
    inline const static array<int, 2> VALUES_RANGE{ 1, 100};
    
public:
    int minProductSum(vector<int>& inputFirst, vector<int>& inputSecond) {
        const size_t size = inputFirst.size();
        vector<int> frequencyFirst(VALUES_RANGE[1] + 1);
        vector<int> frequencySecond(VALUES_RANGE[1] + 1);

        for (int i = 0; i < size; i++) {
            frequencyFirst[inputFirst[i]]++;
            frequencySecond[inputSecond[i]]++;
        }

        int elementsApplied = 0;
        int minProductSum = 0;
        int valueFirst = 0;
        int valueSecond = VALUES_RANGE[1];

        while (elementsApplied < size) {
            while (valueFirst < VALUES_RANGE[1] && frequencyFirst[valueFirst] == 0) {
                valueFirst++;
            }
            while (valueSecond > 0 && frequencySecond[valueSecond] == 0) {
                valueSecond--;
            }
            int frequency = min(frequencyFirst[valueFirst], frequencySecond[valueSecond]);
            minProductSum += frequency * valueFirst * valueSecond;
            frequencyFirst[valueFirst] -= frequency;
            frequencySecond[valueSecond] -= frequency;
            elementsApplied += frequency;
        }
        return minProductSum;
    }
};
