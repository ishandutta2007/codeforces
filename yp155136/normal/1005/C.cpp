#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int a[223456];

int main ()
{
    int n;
    scanf("%d",&n);
    multiset<LL> st;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        st.insert(a[i]);
    }
    int ans = 0;
    for (int i=1;n>=i;i++)
    {
        bool can = false;
        st.erase(st.find(a[i]));
        for (int j=0;33>j;j++)
        {
            if (st.find((1LL<<j) - a[i]) != st.end())
            {
                can = true;
                break;
            }
        }
        st.insert(a[i]);
        ans += can;
    }
    printf("%d\n",n-ans);
}