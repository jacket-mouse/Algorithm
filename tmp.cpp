#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        const int n = 26;
        int ans[n] = {0};
        for (int i = 0; i < words.size(); i++) {
            int tmp[n] = {0};
            for (int j = 0; j < words[i].length(); j++) {
                tmp[words[i].at(j) - 'a']++;
            }
            for (int j = 0; j < n; j++) {
		if(i == 0) ans[j] = tmp[j];
                else ans[j] = min(ans[j], tmp[j]);
            }
        }
        vector<string> f;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ans[i]; j++) {
                string tmp(1, 'a' + i);
                f.push_back(tmp);
            }
        }
        return f;
    }
};

int main(){
	Solution* s = new Solution();
	vector<string> words;
	words.push_back("bella");
	words.push_back("label");
	words.push_back("roller");

	vector<string> ans = s->commonChars(words);
	return 0;
#include <string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        const int n = 26;
        int ans[n] = {0};
        for (int i = 0; i < words.size(); i++) {
            int tmp[n] = {0};
            for (int j = 0; j < words[i].length(); j++) {
                tmp[words[i].at(j) - 'a']++;
            }
            for (int j = 0; j < n; j++) {
                if(i == 0) ans[j] = tmp[j];
                else ans[j] = min(ans[j], tmp[j]);
            }
        }
        vector<string> f;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ans[i]; j++) {
                string tmp(1, 'a' + i);
                f.push_back(tmp);
            }
        }
        return f;
    }
};

int main(){
        Solution* s = new Solution();
        vector<string> words;
        words.push_back("bella");
        words.push_back("label");
        words.push_back("roller");

        vector<string> ans = s->commonChars(words);
        return 0;
}}	
