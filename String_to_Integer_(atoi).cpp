//123
//-123
//-123e-321
//+123E+321
//  123(space in the head)
//Invalid: return 0
//Overflow: return INT_MAX or INT_MIN

//In fact, only consider about the spaces in the head, +/-, and overflow

//Leetcode treats the following input as legal.
//Input:    "  -0012a42"
//Output:   0
//Expected: -12

//Overflow
//Input:    "2147483648"
//Output:   -2147483648
//Expected: 2147483647


class Solution {
public:
    int atoi(const char *str) {

        int i = 0;
        int n = strlen(str), ans = 0;
        bool flag = true;

        while (str[i] == ' ' and i < n)
            i++;

        if (i == n)
            return 0;

        if (str[i] == '+')
            i++;
        else if (str[i] == '-')
        {
            flag = false;
            i++;
        }

        for (; i < n; i++)
        {
            //Not isnum()
            if (!isdigit(str[i]))
                break;
            if (ans > INT_MAX / 10 || ( (ans == INT_MAX/10) && (str[i] - '0' > INT_MAX % 10) ) )
                return flag ? INT_MAX:INT_MIN;
            ans = ans*10 + (str[i] - '0');
        }

        return flag ? ans: -ans;
    }
};
