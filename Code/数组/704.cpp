class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分查找
        int left = 0,right = nums.size()-1;
        while(left<=right){
            int middle = (right - left) / 2 + left;
            if(nums[middle] == target) return middle;
            if(nums[middle]>target){
                right = middle - 1;
            }else{
                left = middle + 1;
            }
        }

        return -1;

    }
};
