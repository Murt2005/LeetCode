class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        ROWS = img1.size();
        COLS = img1[0].size();
        vector<pair<int, int>> img1Freq, img2Freq;
        map<pair<int, int>, int> translationFreq;
        findOnes(img1, img1Freq);
        findOnes(img2, img2Freq);
        for (int i = 0; i < img1Freq.size(); i++) {
            for (int j = 0; j < img2Freq.size(); j++) {
                auto one = img1Freq[i];
                int oneX = one.first;
                int oneY = one.second;

                auto two = img2Freq[j];
                int twoX = two.first;
                int twoY = two.second;

                int xTranslation = oneX - twoX;
                int yTranslation = oneY - twoY;

                translationFreq[{xTranslation, yTranslation}]++;
            }
        }
        int result = 0;
        for (auto& pair : translationFreq) {
            if (pair.second > result) {
                result = pair.second;
            }
        }
        return result;
    }

private:
    int ROWS;
    int COLS;
    void findOnes(vector<vector<int>>& img, vector<pair<int, int>>& imgFreq) {
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (img[row][col] == 1) {
                    imgFreq.push_back({row, col});
                }
            }
        }
    }
};