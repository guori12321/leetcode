class Solution {
public:
    string intToRoman(int num) {
        string ans = "";

        const int N = 13;
        //Note that initialize an array use {}, rather than [];
        int Rnum[N] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string Rstr[N] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        while (num > 0)
        {
            for (int i = 0; i < N; i++)
            {
                //Note / rather than '\'
                //No * for string and int
                for (int j = 0; j < num / Rnum[i]; j++)
                    ans += Rstr[i];
                num = num % Rnum[i];
            }
        }

        return ans;
    }
};

