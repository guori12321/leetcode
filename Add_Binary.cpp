//The insert to string:
//str.insert(pos, repeatTime, char)
//str.insert(pos, str2)

class Solution {
public:
    string addBinary(string a, string b) {
        const int lena = a.length(), lenb = b.length();
        const int len = lena > lenb ? lena : lenb;

        int carry = 0;
        string ans;
        char chara, charb;

        for (int i = 0; i < len; i++)
        {
            if (i >= lena)
                chara = '0';
            else
                chara = a[lena-1 -i ];
            if (i >= lenb)
                charb = '0';
            else
                charb = b[lenb-1 - i ];

            int t = int(chara - '0') + int(charb -'0') + carry;
            carry = t / 2;

            ans.insert(0, 1, t%2 +'0');
        }

        if (carry == 1)
            ans.insert(0, 1, '1');

        return ans;
    }
};
