//I submitted 9 times and finally AC...
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        //not tokens.reverse()
        reverse(tokens.begin(), tokens.end());

        stack<int> num;

        while (tokens.size() > 0)
        {
            //tokens.back(), not tokens.top()
            string t = tokens.back();
            tokens.pop_back();

            //isdigit(char), not isdigit(string), not string::isdigit(string)
            //"+3" is a number, not a operator
            if (t.size() > 1 || isdigit(t[0]) )
            //stoi(), not string::stoi()
                num.push(stoi(t));
            else
            {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();

                //b-a, not a-b, for we are in a stack!!!
                if (t == "+")
                    num.push(b+a);
                if (t == "-")
                    num.push(b-a);
                if (t == "*")
                    num.push(b*a);
                if (t == "/")
                    num.push(b/a);
            }
        }

        return num.top();
    }
};
