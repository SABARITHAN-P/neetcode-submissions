class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            nums.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            nums.push_back(nums2[j]);
            j++;
        }
        int N = nums.size();

        if(N % 2 == 1) {
            return nums[N / 2];
        }

        return (nums[N / 2 - 1] + nums[N / 2]) / 2.0;
    }
};
