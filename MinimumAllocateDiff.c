#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmp);

    int minDiff = abs(arr[1] - arr[0]);
    for (int i = 1; i < arrSize - 1; i++) {
        int diff = abs(arr[i + 1] - arr[i]);
        if (diff < minDiff)
            minDiff = diff;
    }

    int count = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i + 1] - arr[i] == minDiff)
            count++;
    }
    int** result = (int**)malloc(count * sizeof(int*));
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    
    int idx = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i + 1] - arr[i] == minDiff) {
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = arr[i];
            result[idx][1] = arr[i + 1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    *returnSize = count;
    return result;
}
