class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int minLength = INT_MAX;
        int n = strs.size();

        if (strs.size() == 0)
            return "";

        for (int i = 0; i < n; i++)
        {
            string t = strs[i];
            minLength = minLength < t.length() ? minLength : t.length();
        }

        for (int i = 0; i < minLength; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }

        //Not Null, because perhaps all the strings are the same
        //minLength, rather than minLength - 1
        return strs[0].substr(0, minLength);
    }
};

