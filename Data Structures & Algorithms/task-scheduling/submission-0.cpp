class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        // Find the maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Count how many tasks have the maximum frequency
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq)
                maxCount++;
        }

        // Calculate the minimum required slots
        int ans = (maxFreq - 1) * (n + 1) + maxCount;

        // Answer cannot be less than total number of tasks
        return max((int)tasks.size(), ans);
    }
};