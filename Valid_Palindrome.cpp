class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "")
        {
            return true;
        }

        int n = s.length();
        int i = 0, j = n-1;

        while (i < j && i < n && j >= 0)
        {
            //consider alphanumeric: Numbers!
            //'0' <= s[i] <= '9' You can NOT write in this way, but '0' <= s[i] && s[i] <= '9'
            //Note that there is 'isaplha' and 'isalnum' functions.
            //while ( !( isalnum(s[i]) || '0' <= s[i] <= '9' ) && (i < n)  )
            while ( !( isalnum(s[i]) ) && (i < n)  )
                i++;
            //while ( !( isalnum(s[j]) || '0' <= s[j] || s[j] <= '9') && (j >= 0) )
            while ( !( isalnum(s[j]) ) && (j >= 0) )
                j--;

            if (i >= j || i >= n || j < 0)
                return true;

            if (s[i] != s[j] && ( abs(s[i] - s[j]) != abs('A'-'a')) )
                return false;

            //Attention!
            i++;
            j--;
        }

        return true;
    }
};
