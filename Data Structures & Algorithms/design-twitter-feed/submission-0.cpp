class Twitter {
public:
    int timer;

    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {(time, tweetId)}
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;
        // (time, tweetId)

        // Add user's own tweets
        for(auto &tweet : tweets[userId]){
            pq.push(tweet);
        }

        // Add tweets of everyone the user follows
        for(int followee : following[userId]){
            for(auto &tweet : tweets[followee]){
                pq.push(tweet);
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if(followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};