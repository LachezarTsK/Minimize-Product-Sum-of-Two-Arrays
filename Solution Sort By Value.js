
/**
 * @param {number[]} inputFirst
 * @param {number[]} inputSecond
 * @return {number}
 */
var minProductSum = function (inputFirst, inputSecond) {
    inputFirst.sort((x, y) => x - y);
    inputSecond.sort((x, y) => x - y);
    const size = inputFirst.length;
    let minProductSum = 0;
    for (let i = 0; i < size; i++) {
        minProductSum += inputFirst[i] * inputSecond[size - i - 1];
    }
    return minProductSum;
};
