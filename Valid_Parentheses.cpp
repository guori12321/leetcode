class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        string left = "({[";
        string right = "]})";

        for (int i = 0; i < s.size(); i++)
            if (left.find(s[i]))
                sta.push(s[i]);
            else
            {
                if (sta.empty)
                    return false;

                if (s[i] == stack.top())
                    sta.pop();
                else
                    return false;
            }
        return true;
    }
};
