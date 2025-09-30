class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
    
        int oddCount = 0, result = 0;
        
        for (int num : nums) {
            oddCount += num & 1;
            result += prefixCount[oddCount - k];
            prefixCount[oddCount]++;
        }
        
        return result;
    }
};

/*

[1,1,0,1,1] k=3
[1,2,2,3,4]
*/