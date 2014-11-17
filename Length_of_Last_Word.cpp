class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s);
        int last = n-1;

        while (last >= 0 && s[last] == ' ')
            last--;
        if (last < 0)
            return 0;

        int start = last;
        while (start >= 0 && s[start] != ' ')
            start--;

        //It is okay if start == -1

        return (last - start);
    }
};
