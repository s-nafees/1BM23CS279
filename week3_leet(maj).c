int majorityElement(int* nums, int numsSize) {
    int ele = nums[0], count = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == ele) {
            count++;
        } 
        else {
            if (count == 0) {
                ele = nums[i];
                count = 0;
            }
        }
    }
    return ele;
}
