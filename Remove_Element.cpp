//Note that the last a few elements can be elem as well.
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int last = n-1;

        int i = 0;
        while (i <= last)
        {
            if (A[i] == elem)
            {
                A[i] = A[last];
                last--;
            }
            //Only when A[i] is replaced with non elem elements, can i be added.
            else
                i++;
        }

        //return the number, so last + 1
        return last+1;
    }
};
