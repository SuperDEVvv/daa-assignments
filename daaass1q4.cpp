#include <iostream>
using namespace std;

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;

    int currentSum = 0;
    int maxSum = arr[0];

    for (int i = 0; i < n; i++) {
        currentSum = currentSum + arr[i];

        if (currentSum > maxSum)
            maxSum = currentSum;

        if (currentSum < 0)
            currentSum = 0;
    }

    cout << "Maximum subarray sum is: " << maxSum;
    return 0;
}
