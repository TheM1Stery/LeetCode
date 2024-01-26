#include <stdio.h>


int removeElement(int* nums, int numsSize, int val) {
    int new = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] != val)
            nums[new++] = nums[i];
    }
    return new;
}


void print(int* arr, size_t length){
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    int input_arr[] = {3,2,2,3};
    int skip = 3;
    size_t length = sizeof(input_arr) / sizeof(input_arr[0]);
    printf("Input: ");
    print(input_arr, length);
    int result = removeElement(input_arr, length, skip);
    printf("Result: %d\n", result);
    printf("Array: ");
    print(input_arr, sizeof(input_arr) / sizeof(input_arr[0]));

    return 0;
}
