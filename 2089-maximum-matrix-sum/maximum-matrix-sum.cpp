class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int numberOfNegatives = 0;
        long long matrixSum = 0;
        int smallestAbsVal = INT_MAX;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] < 0) {
                    numberOfNegatives++;
                }

                if (abs(matrix[row][col]) < smallestAbsVal) {
                        smallestAbsVal = abs(matrix[row][col]);
                    }

                matrixSum += abs(matrix[row][col]);
            }
        }

        if (numberOfNegatives % 2 == 0) {
            return matrixSum;
        }

        return matrixSum - 2 * smallestAbsVal;
    }
};


/*


if we have an even number of negatives, everything can be made positive

if we have an odd number of negatgives, we can make everything but one positive

find number of negative values, look if even or odd number of negatives

if positive value:
- sum all the values up

if negative value:
- find smallest abs value in the square
- sum of the rest of the values for result



[2,9,3]
[5,4,-4]
[1,7,1]]


*/