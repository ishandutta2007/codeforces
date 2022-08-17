#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 100500;

int A[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    stack<int> st;
    int ans = 0;
    for (int it = 0; it < 2; it++)
    {
        for (int i = 0; i < n; i++)
        {
            int x = A[i];
            while (!st.empty() && st.top() < x)
                st.pop();
            if (!st.empty())
                ans = max(ans, x ^ st.top());
            st.push(x);
        }
        while (!st.empty())
            st.pop();
        reverse(A, A + n);
    }
    printf("%d\n", ans);

}