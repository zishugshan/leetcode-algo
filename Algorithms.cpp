// day1 : 1>> https://leetcode.com/problems/binary-search/

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = h-(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
    }
   
