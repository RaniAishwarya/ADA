int cmp(const void*a,const void*b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    if (strlen(str1) == strlen(str2)) {
        return strcmp(str1, str2);
    }
    return strlen(str1) - strlen(str2);
}
char * kthLargestNumber(char ** nums, int numsSize, int k){
qsort(nums,numsSize,sizeof(char*),cmp);
return nums[numsSize-k];
}
