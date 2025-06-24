class Solution {
public:
    string aligned(string str, int N) {
        istringstream iss(str);
        vector<string> tocken;
        string ans, word;
        int siz = 0;

        while (iss >> word) {
            // cout << "string " << word << nn;
            tocken.push_back(word);
            siz += word.size();
        }

        int totalSpace = N - siz;
        int gap = tocken.size() - 1;

        if (gap >= 1) {
            int spacePerGap = totalSpace / gap;
            int extraSpace = totalSpace % gap;

            for (int i = 0; i < tocken.size(); i++) {
                ans += tocken[i];
                if (i < gap) {
                    ans.append(spacePerGap + (i < extraSpace ? 1 : 0), ' ');
                }
            }
        } else {
            ans += tocken.front();
            ans.append(totalSpace, ' ');
        }
        return ans;
    }

    vector<string> modify(vector<string>& words, int N) {
        int i, n = words.size();
        vector<string> ans;
        for (i = 0; i < n - 1; i++) {
            string line = words[i];
            string line_ = aligned(line, N);
            // cout << "Line: " << line_ << nn;
            ans.push_back(line_);
        }
        string last = words.back();
        int extra_space = N - last.size();
        last.append(extra_space, ' ');
        ans.push_back(last);

        return ans;
    }

    vector<string> fullJustify(vector<string>& words, int maxwidth) {
        int i, n = words.size();
        vector<int> siz(n, 0);
        for (i = 0; i < n; i++) {
            siz[i] = words[i].size();
        }

        vector<string> ans;
        string temp;
        int threshold = 0;
        i = 0;

        while (i < n) {
            if (threshold + siz[i] + (threshold != 0) <= maxwidth) {
                if (threshold == 0) {
                    threshold += siz[i];
                    temp += words[i];
                } else {
                    threshold += siz[i] + 1;
                    temp += " ";
                    temp += words[i];
                }
            } else {
                ans.push_back(temp);
                temp.clear();
                threshold = 0;
                i -= 1;
            }
            i++;
        }

        ans.push_back(temp);
        ans = modify(ans, maxwidth);
        return ans;
    }
};