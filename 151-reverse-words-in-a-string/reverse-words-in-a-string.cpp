class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                helper(s, i);
            }

            while (i < s.length() && s[i] != ' ') {
                i++;
            }
        }

        int readPtr = 0;
        int writePtr = 0;
        while (readPtr < s.length()) {
            while (readPtr < s.length() && s[readPtr] == ' ') {
                readPtr++;
            }

            while (readPtr < s.length() && s[readPtr] != ' ') {
                s[writePtr] = s[readPtr];
                writePtr++;
                readPtr++;
            }

            while (readPtr < s.length() && s[readPtr] == ' ') {
                readPtr++;
            }

            if (readPtr < s.length()) {
                s[writePtr] = ' ';
                writePtr++;
            }

        }

        return s.substr(0, writePtr);
    }
    

private:
    void helper(string& s, int startIdx) {
        int endIdx = startIdx;

        while (endIdx < s.length() && s[endIdx] != ' ') {
            endIdx++;
        }

        endIdx--;

        while (startIdx < endIdx) {
            char temp = s[startIdx];
            s[startIdx] = s[endIdx];
            s[endIdx] = temp;
            startIdx++;
            endIdx--;
        }

    }
};

/*

given: string s

want: reverse the order of the words


a word is defiend as a sequence of non-space characters
there can be multiple spaces between words


return: string of the words in reverse order concatendated by a single space


"the sky is blue"

eulb si kys eth
s
    e

blue
 se
"a good   example"

example        good a
^     r

algorithm:
- reverse the input string
- iterate through the reversed input string
- if I encounter the start of a new word at my read ptr (ie not a space) call my helper function
- helper function:
    - i pass the index of the start of the word
    - iterate to find the last index of the word
    - swap the startIndx and lastIndx
    - increment startIndx and decrement lastIndx till startIndx < lastIndx
- call my other helper function that will:
    - have a readptr and a writeptr
    - readPtr will read chars and writeptr will write chars
    - this will prevent the output from having more than one space inbetween words
- return s.substr(0, writePtr)


eth kys si eulb





*/