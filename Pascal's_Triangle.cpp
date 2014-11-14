//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ansList;

        if (numRows == 0)
            return ansList;

        vector<int> t;
        t.push_back(1);
        ansList.push(t);

        for (int i = 1; i < numRows; i++)
        {
            vector<int> ans;
            vector<int> last = ansList.back();

            ans.push_back(1);
            for (int j = 1; j < i; j++)
            {
                ans.push_back(last[j-1] + last[j]);
            }
            ans.push_back(1);

            ansList.push_back(ans);
        };

        return ansList;
    }
};
