
public class Solution {

    private static final int[] VALUES_RANGE = new int[]{1, 100};

    public int minProductSum(int[] inputFirst, int[] inputSecond) {
        final int size = inputFirst.length;
        int[] frequencyFirst = new int[VALUES_RANGE[1] + 1];
        int[] frequencySecond = new int[VALUES_RANGE[1] + 1];

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
            int frequency = Math.min(frequencyFirst[valueFirst], frequencySecond[valueSecond]);
            minProductSum += frequency * valueFirst * valueSecond;
            frequencyFirst[valueFirst] -= frequency;
            frequencySecond[valueSecond] -= frequency;
            elementsApplied += frequency;
        }
        return minProductSum;
    }
}
