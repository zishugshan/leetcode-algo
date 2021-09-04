// day1 : 1>> https://leetcode.com/problems/contains-duplicate/

    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i =0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>1) return true;
        }
        return false;
        
    }


// day1 : 2>> https://leetcode.com/problems/maximum-subarray/

    int maxSubArray(vector<int>& nums) {
        int sumT = -100000;
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum = sum + nums[i]; 
            sumT = max(sumT,sum);
            if(sum<0) sum = 0;
        }
        return sumT;   
    }


// day2 : 1>> https://leetcode.com/problems/two-sum/

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target/2 && m[target-nums[i]] != i){
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
            }
            else if(m[target-nums[i]]>0 && m[target-nums[i]] != i){
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
            }
            if(!v.empty()) break;
        }
        return v;
    }


// day2 : 2>> https://leetcode.com/problems/merge-sorted-array/

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>v(m,0);
        for(int i=0;i<m;i++){
            v[i]=nums1[i];
        }
        int i=0;
        int j=0;
        int k=0;
        while(i<m && j<n){
            if(v[i]<nums2[j]){
                nums1[k]=v[i];
                k++;i++;
            }
            else{
                nums1[k]=nums2[j];
                k++;j++;
            }
        }
        while(i<m){
            nums1[k]=v[i];
            k++;i++;
        }
        while(j<n){
            nums1[k]=nums2[j];
            k++;j++;
        }
    }


// day3 : 1>> https://leetcode.com/problems/intersection-of-two-arrays-ii/

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]) {
                    v.push_back(nums2[j]);
                    vector<int> :: iterator it = nums2.begin()+j;
                    nums2.erase(it);
                    break;
                } 
            }
        }
        return v;
    }


// day3 : 2>> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    int maxProfit(vector<int>& prices) {
        int minP = 10010;
        int maxG = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minP){
                minP = prices[i];
            }
            else{
                int G = prices[i]-minP;
                maxG = max(G,maxG);
            }
        }
        return maxG; 
    }


// day4 : 1>> https://leetcode.com/problems/reshape-the-matrix/

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(r*c != m*n){
            return mat;
        }
        vector<vector<int>> vv;
        vector<int>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(mat[i][j]);
                if(v.size()==c){
                   vv.push_back(v);
                    v.clear();
                }
            }
        }
        return vv;
    }


// day4 : 2>> https://leetcode.com/problems/pascals-triangle/


