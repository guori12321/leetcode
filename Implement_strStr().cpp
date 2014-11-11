/* Attention!
Input:      "", ""
Output:     -1
Expected:   0
*/

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int n = strlen(haystack);
        int m = strlen(needle);

        //Attention that needle == ""
        if (m == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i+j >= n)
                    return -1;
                if (haystack[i+j] != needle[j])
                    break;
                if (j == m -1)
                    return i;
            }
        }
        return -1;
    }
};
