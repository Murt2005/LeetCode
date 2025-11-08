class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    unordered_map<int, int> inValidFreq;
    int maxHeapTrueSize = 0;
    int minHeapTrueSize = 0;

    void addValue(int val) {
        if (maxHeap.empty() || val <= maxHeap.top()) {
            maxHeap.push(val);
            maxHeapTrueSize++;
        } else {
            minHeap.push(val);
            minHeapTrueSize++;
        }
        rebalanceHeaps();
    }

    void removeValue(int val) {
        inValidFreq[val]++;
        if (!maxHeap.empty() && val > maxHeap.top()) {
            minHeapTrueSize--;
            rebalanceHeaps();
        } else if (!maxHeap.empty() && val <= maxHeap.top()) {
            maxHeapTrueSize--;
            rebalanceHeaps();
        }
    }

    void rebalanceHeaps() {
        while (minHeapTrueSize > maxHeapTrueSize) {
            int val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
            minHeapTrueSize--;
            maxHeapTrueSize++;
        }

        while (maxHeapTrueSize - minHeapTrueSize > 1) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
            maxHeapTrueSize--;
            minHeapTrueSize++;
        }
    }

    void cleanHeaps() {
        while (!maxHeap.empty() && inValidFreq[maxHeap.top()] > 0) {
            inValidFreq[maxHeap.top()]--;
            maxHeap.pop();
        }

        while (!minHeap.empty() && inValidFreq[minHeap.top()] > 0) {
            inValidFreq[minHeap.top()]--;
            minHeap.pop();
        }
    }

    double calculateMedian() {
        cleanHeaps();
        if (minHeapTrueSize == maxHeapTrueSize) {
            int smallerVal = maxHeap.top();
            int largerVal = minHeap.top();
            return ((double)smallerVal + largerVal) / 2;
        }

        return maxHeap.top();
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> result;

        for (int i = 0; i < k; i++) {
            addValue(nums[i]);
        }
        double median = calculateMedian();
        result.push_back(median);

        int leftPtr = 0;
        for (int i = k; i < n; i++) {
            addValue(nums[i]);
            removeValue(nums[i - k]);
            double median = calculateMedian();
            result.push_back(median);
        }

        return result;
    }
};

/*

given: arr of ints, and an int k

return: median array for each window in the original array

data structures:
- use a maxHeap and minHeap and unordered_map
- maxHeap contains min ints of window
- minHeap contains max ints of window
- unordered_map to store values outside of window that are still in a heap

algorithm:
- step 1, put all values into maxHeap or minHeap from the first window, start by putting values into the maxHeap then balance as needed
- maintain that the size of the maxHeap and minheap excluding values outside window that the sizes don't differ by more than 1
- keep track of the "valid" size for each heap, 
- for each window the median is the top of the heap that is greater by 1, if sizes equal then median = (top + top) / 2
- if the top of a heap is a value from outside window, pop it, keep popping until valid tops
- clean the heaps after every new window before calculating the median value
- when window is shifted, add new value based on the following: if value <= maxHeap.top() add to maxHeap otherwise add to minheap
    - check if maxHeap is empty before doing maxHeap.top() for adding
- after adding a value maintain that the invariant maxHeap.size() >= minHeap.size() && maxHeap.size() - minHeap.size() <= 1
- when removing values find which value is being removed, increment teh conuter in the map, and update the true sizes of the heap
- to rebalance check which heap is greater and move elemtns accordingly from bigger heap to smaller heap while keeping track of sizes

[1,3,-1,-3,5,3,6,7] k = 3
 ^    ^


minHeap:

maxHeap:

unordered_map:


*/