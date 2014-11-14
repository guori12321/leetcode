//Add "(" can be treated as push a stack, and ")" as pop.
class Solution {
public:
    int tot;
    string s = "";
    vector<string> ans;
    vector<int> stack;
    //It's not necessary to use a real stack here, an integer can easily show how many "(" in the stack

    void DFS(int k)
    {
        if (k == 0)
        {
            k = stack.size();
            for (int i = 0; i < k; i++)
                s += ")";
            ans.push_back(s);
            //There is no "delete" in C++. We use "erase".
            s.erase(s.size()-k, k);
            return;
        }

        s += "(";
        stack.push_back(1);
        DFS(k-1);
        stack.pop_back();
        s.erase(s.size()-1, 1);

        if (stack.size() > 0)
        {
            stack.pop_back();
            s += ")";
            DFS(k);
            stack.push_back(0);
            s.erase(s.size()-1, 1);
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        DFS(n);
        return ans;
    }
};
