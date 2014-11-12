//Symbol    Value
//I         1
//V         5
//X         10
//L         50
//C         100
//D         500
//M         1,000
//
//When a small number is on the left of a large number, then we minus the small note, otherwise we add it.

//Learn to use map in C++

class Solution {
public:
    int romanToInt(string s) {
        if (s == "")
            return 0;

        int n = s.size();
        int ans = 0;

        map<char, int> ROME;
        ROME['I'] = 1;
        ROME['V'] = 5;
        ROME['X'] = 10;
        ROME['L'] = 50;
        ROME['C'] = 100;
        ROME['D'] = 500;
        ROME['M'] = 1000;

        for (int i = 0; i < n-1; i++)
            //In case of i == largeLoc, we should add them
            if (ROME[ s[i] ] < ROME[ s[i+1] ])
                ans -= ROME[ s[i] ];
            else
                ans += ROME[ s[i] ];

        ans += ROME[ s[n-1] ];

        return ans;
    }
};
