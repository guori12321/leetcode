//think simple and write your code brief enough

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2)
            return n;

        index = 2;
        for (int i = 2; i < n; i++)
            if (A[i] > A[index -2])
                A[index++] = A[i];
        return i;
    }
};

//class Solution {
//public:
//    int removeDuplicates(int A[], int n) {
//        int i = 1, j = 0;
//        bool flag = false;
//
//        if (n <= 2)
//            return n;
//
//        while (i < n && j < n)
//            if (A[i] == A[i-1] || i == j)
//            {
//                if (flag == false || i != j)
//                {
//                    i++;
//                    flag = true;
//                }
//                else
//                {
//                    flag = false;
//                    while (j < n-1 && A[j] <= A[i])
//                        j++;
//                    if (j == n-1)
//                        if (A[i] == A[j])
//                            return i;
//                        else{
//                            A[i] = A[j];
//                            i++;
//                            return i;
//                        }
//                    A[i] = A[j];
//                    i++;
//                }
//            }
//            else
//            {
//                i++;
//                flag = false;
//            }
//
//        return i;
//    }
//};
//
