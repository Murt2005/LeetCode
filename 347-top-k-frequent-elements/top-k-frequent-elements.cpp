class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap; // val -> freq
        
        
        auto cmp = [](const auto& a, const auto& b) {
            return a.second > b.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (int num : nums) {
            freqMap[num]++;
        }        

        vector<int> result;

        for (const auto& pair : freqMap) {
            minHeap.push(pair);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {
            auto pair = minHeap.top();
            minHeap.pop();
            int val = pair.first;
            result.push_back(val);
        }

        return result;
    }
};

/*

given: arr of ints and an int k

return:return k most frequent elements, can be in any order

ds:
- unordered_map<int, int> val -> freq
- priority_queue (minHeap)

algorithm:
- iterate through nums arr
- build the freqMap
- for each pair in freq map
- then iterate through freqMap and put vals in minHeap
- maintain that the minHeap is at most size k
- if minHeap is bigger than k, we pop the top val
- after iterating through freqMap
- pop all values from minHeap, this will be our result



*/