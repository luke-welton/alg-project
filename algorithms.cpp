#include "algorithms.h"
#include <algorithm>
using namespace std;

/**
 * Performs the first algorithm.
 * @param x - The array being processed
 * @param p - The beginning bound to look at in the array
 * @param q - The closing bound to look at in the array
 * @return The maximum sum of the elements within the bounds on the array
 **/
int algorithm1(const int x[], int p, int q) {
    int maxSoFar = 0;

    for (int l = p; l <= q; l++) {
        for (int u = l; u <= q; u++) {
            int sum = 0;

            for (int i = l; i <= u; i++) {
                sum += x[i];
            }

            maxSoFar = max(maxSoFar, sum);
        }
    }

    return maxSoFar;
}

/**
 * Performs the second algorithm.
 * @param x - The array being processed
 * @param p - The beginning bound to look at in the array
 * @param q - The closing bound to look at in the array
 * @return The maximum sum of the elements within the bounds on the array
 **/
int algorithm2(const int x[], int p, int q) {
    int maxSoFar = 0;

    for (int l = p; l <= q; l++) {
        int sum = 0;

        for (int u = l; u <= q; u++) {
            sum += x[u];
            maxSoFar = max(maxSoFar, sum);
        }
    }

    return maxSoFar;
}

/**
 * Performs the third algorithm.
 * @param x - The array being processed
 * @param l - The lower bound to look at in the array
 * @param u - The upper bound to look at in the array
 * @return The maximum sum of the elements within the bounds on the array
 **/
int algorithm3(const int x[], int l, int u) {
    if (l > u) {
        return 0;
    } else if (l == u) {
        return max(0, x[l]);
    }

    int m = (l + u) / 2;

    int sum = 0, maxToLeft = 0;
    for (int i = m; i >= l; i--) {
        sum += x[i];
        maxToLeft = max(maxToLeft, sum);
    }

    int maxToRight = sum = 0;
    for (int i = m + 1; i <= u; i++) {
        sum += x[i];
        maxToRight = max(maxToRight, sum);
    }

    int maxCrossing = maxToLeft + maxToRight;
    int maxInA = algorithm3(x, l, m);
    int maxInB = algorithm3(x, m + 1, u);

    return max(maxCrossing, max(maxInA, maxInB));
}

/**
 * Performs the fourth algorithm.
 * @param x - The array being processed
 * @param p - The beginning bound to look at in the array
 * @param q - The closing bound to look at in the array
 * @return The maximum sum of the elements within the bounds on the array
 **/
int algorithm4(const int x[], int p, int q) {
    int maxSoFar = 0, maxEndingHere = 0;

    for (int i = p; i <= q; i++) {
        maxEndingHere = max(0, maxEndingHere + x[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}