//Very easy but still need much attention.
class Solution {
public:
    void reverseWords(string &s) {
        //Add an extra space in the end so that we do not need to check weather we've reached the end, because there will be no character in the end.
        s += " ";

        vector<int> start;
        vector<int> end;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                start.push_back(i);
                while (s[i] != ' ')
                    i++;
                end.push_back(i-1);
            }
        }

        string ans = "";
        while (start.size() > 1)
        {
            int i = start.back();
            start.pop_back();
            int j = end.back();
            end.pop_back();

            ans = ans + s.substr(i, j-i+1) + " ";
        }

        //The last string don't need space in the end. However, the answer may be empty, so we need to judge weather we still have one more string.
        if (start.size() == 1)
            ans += s.substr(start.back(), end.back() - start.back() + 1);

        s = ans;
        return;
    }
};
