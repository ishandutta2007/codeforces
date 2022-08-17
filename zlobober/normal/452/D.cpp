#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int k, n1, n2, n3, t1, t2, t3;
    scanf("%d %d %d %d %d %d %d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
    vector<int> A(n1, 0), B(n2, 0), C(n3, 0);
    for (int i = 0; i < k; i++)
    {
        int a = min_element(A.begin(), A.end()) - A.begin();
        int b = min_element(B.begin(), B.end()) - B.begin();
        int c = min_element(C.begin(), C.end()) - C.begin();
        int x = max(max(A[a], B[b] - t1), C[c] - t1 - t2);
        A[a] = x + t1;
        B[b] = x + t1 + t2;
        C[c] = x + t1 + t2 + t3;
    }
    printf("%d\n", *max_element(C.begin(), C.end()));
}