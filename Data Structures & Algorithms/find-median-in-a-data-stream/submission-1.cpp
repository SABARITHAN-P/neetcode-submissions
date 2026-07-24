class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        vector<int> nums;
        priority_queue<int, vector<int>, greater<int>> temp = pq;
        while(!temp.empty()){
            nums.push_back(temp.top());
            temp.pop();
        }
        int n = nums.size();
        if(n % 2 == 0){
            return (nums[n/2] + nums[n/2 - 1]) / 2.0;
        }
        return nums[n/2];
    }
};
