
/**
 * @param {number[]} inputFirst
 * @param {number[]} inputSecond
 * @return {number}
 */
var minProductSum = function (inputFirst, inputSecond) {
    const VALUES_RANGE = [1, 100];
    const size = inputFirst.length;
    const frequencyFirst = new Array(VALUES_RANGE[1] + 1).fill(0);
    const frequencySecond = new Array(VALUES_RANGE[1] + 1).fill(0);

    for (let i = 0; i < size; i++) {
        frequencyFirst[inputFirst[i]]++;
        frequencySecond[inputSecond[i]]++;
    }

    let elementsApplied = 0;
    let minProductSum = 0;
    let valueFirst = 0;
    let valueSecond = VALUES_RANGE[1];

    while (elementsApplied < size) {
        while (valueFirst < VALUES_RANGE[1] && frequencyFirst[valueFirst] === 0) {
            valueFirst++;
        }
        while (valueSecond > 0 && frequencySecond[valueSecond] === 0) {
            valueSecond--;
        }
        let frequency = Math.min(frequencyFirst[valueFirst], frequencySecond[valueSecond]);
        minProductSum += frequency * valueFirst * valueSecond;
        frequencyFirst[valueFirst] -= frequency;
        frequencySecond[valueSecond] -= frequency;
        elementsApplied += frequency;
    }
    return minProductSum;
};
