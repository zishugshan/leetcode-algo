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


// day1 : 2>> https://leetcode.com/problems/first-bad-version/

    int firstBadVersion(int n) {
        int l = 1;
        int h = n;
        int badVersion = 0;
        while(l<=h){
            int bad = l + (h-l)/2;
            if(isBadVersion(bad)){
                badVersion = bad;
                h = bad-1;
            }
            else{
                l = bad+1;
            }
        }
        return badVersion;
    }


// day1 : 3>> https://leetcode.com/problems/search-insert-position/

    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int idx = -1;
        while(l<=h){
            int mid = h-(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                l = mid+1;
                idx = mid+1;
            }
            else{
                h = mid-1;
                idx = mid;
            }       
        }
        return idx;
    }


// day2 : 1>> https://leetcode.com/problems/squares-of-a-sorted-array/

    vector<int> sortedSquares(vector<int>& nums) {
        multimap<int,int>mm;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            mm.insert({nums[i]*nums[i],nums[i]});
        }
        for(auto it = mm.begin(); it != mm.end();it++){
            v.push_back(it->first);
        }
        return v;
    }


// day2 : 2>> https://leetcode.com/problems/rotate-array/

    void rotate(vector<int>& nums, int kk) {
        int n =nums.size();
        int k = kk%n;
        int arr[n-k];
        for(int i=0;i<n-k;i++){
            arr[i]=nums[i];
        }
        for(int i =0;i<k;i++){
            nums[i]=nums[n-k+i];
        }
        for(int i=0;i<n-k;i++){
            nums[k+i]=arr[i];
        }
    }


// day3 : 1>> https://leetcode.com/problems/move-zeroes/

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]!=0) arr[j++]=nums[i];
            }
        
         for(int k=0;k<n;k++){
            nums[k]=arr[k];
        }
        
        }
    

// day3 : 2>> https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<numbers.size();i++){
            m.insert({numbers[i],i});
        }
        
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==target/2){
                v.push_back(i+1);
                v.push_back(i+2);
            }
            else if((m[target-numbers[i]])>0){
                v.push_back(i+1);
                v.push_back(m[target-numbers[i]]+1);
            }
            if(!v.empty()) break;
        }
        return v;
    }


// day4 : 1>> https://leetcode.com/problems/reverse-string/

    void reverseString(vector<char>& s) {
        int l=0;
        int h=s.size()-1;
        while(l<h){
            swap(s[l],s[h]);
            l++;h--;
        }
        
    }


// day4 : 2>> https://leetcode.com/problems/reverse-words-in-a-string-iii/

    string reverseOne(string &s,int i,int j){
        while(i<j){
            swap(s[i++],s[j--]);
        }
        return s;
    }
    string reverseWords(string s) {
        int l=0;
        int r=1;
        while(l<r){
            if(r>s.size()-1){
                int start = l;
                reverseOne(s,start,s.size()-1);
                break;
            }
            if(s[r]==' '){
                int start = l;
                int end = r-1;
                reverseOne(s,start,end);
                l=r+1;
                r=r+2;
            }
            else{
                r++;
            }
        }
        return s; 
    }



// day5 : 1>> https://leetcode.com/problems/middle-of-the-linked-list/

    ListNode* middleNode(ListNode* head) {
        ListNode * temp = head;
        int count =0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        int newH = count/2;
        temp = head;
        while(newH--){
            temp = temp->next;
        }
        head = temp;
        return head;
    }


// day5 : 2>> https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int count =0;
        while(temp){
            temp=temp->next;
            count++;
        }
        temp=head;
        int fromStart = count - n -1;
        if(count==n) {
            head=temp->next;
            return head;
        }
        temp = head;
        while(fromStart--){
            temp = temp->next;
        }
        if(n==1){
            temp->next = NULL;
            return head;
        }
        ListNode * delt = temp->next;
        temp->next = delt->next;
        return head;
    }


//day6 : 1>> 


        
        
 
   
