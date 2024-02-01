#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))


int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left / 2);
        if (nums[mid] == target)
            return mid;

        if (target > nums[mid]) {
            left = mid + 1;
        } else if (target < nums[mid]){
            right = mid - 1;
        }
    }

    return left;
}

void print_arr(int* arr, int size){
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    int nums[] = {1, 3, 5, 6};
    int target = 1;

    print_arr(nums, ARRAY_SIZE(nums));
    printf("Target: %d\n", target);
    int answer = searchInsert(nums, ARRAY_SIZE(nums), target);
    printf("Answer: %d\n", answer);

    return EXIT_SUCCESS;
}
