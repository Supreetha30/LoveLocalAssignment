#include <stdio.h>
#include <stdlib.h>

int* majority_elements(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int candidate1 = -1, candidate2 = -1;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    if (count1 > numsSize / 3) {
        result[(*returnSize)++] = candidate1;
    }
    if (count2 > numsSize / 3) {
        result[(*returnSize)++] = candidate2;
    }

    return result;
}

int main() {
    int nums[100]; 
    int numsSize;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &numsSize);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* result = majority_elements(nums, numsSize, &returnSize);

    printf("Majority Elements: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
