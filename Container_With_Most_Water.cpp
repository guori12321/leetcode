//It's obvious a greedy algorithm.
//Let (a, b) be the answer. Initially i = 0, j = n-1, and if (height[i] < height[j]) we i++, else j--.
//Assume that it is i that reach a first (rather than j reach b).
//As (a, b) is the best solution, all the walls between (b+1, j) is worse than b, so we continue to j--, until we reach (a,b).
class Solution {
public:
    int area(int i, int j, vector<int> &height)
    {
        return abs(j - i)*min(height[j], height[i]);
    }

    int maxArea(vector<int> &height) {
        int n = height.size();
        int ans = 0;

        int i = 0, j = n-1;

        while (i < j && i < n && j > 0)
        {
            ans = max(area(i,j, height), ans);

            if (height[i] < height[j])
                i++;
            else j--;
        }

        return ans;
    }
};

