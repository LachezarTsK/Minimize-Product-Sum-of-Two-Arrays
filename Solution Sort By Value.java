
import java.util.Arrays;

public class Solution {

    public int minProductSum(int[] inputFirst, int[] inputSecond) {
        Arrays.sort(inputFirst);
        Arrays.sort(inputSecond);
        final int size = inputFirst.length;
        int minProductSum = 0;
        for (int i = 0; i < size; i++) {
            minProductSum += inputFirst[i] * inputSecond[size - i - 1];
        }
        return minProductSum;
    }
}
