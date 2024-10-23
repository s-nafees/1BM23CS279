int majorityElement(int* nums, int numsSize) {
    int n = numsSize;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j = 0; j<n;j++){
            if(nums[j]==nums[i]){
                count++;
            }
        }
        if(count > n/2)
        {
            return nums[i];
        }
    }
    return -1;
}
