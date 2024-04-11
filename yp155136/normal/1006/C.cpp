#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200006;

LL pre[N],suf[N],a[N];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
    }
    for (int i=1;n>=i;i++)
    {
        pre[i] = pre[i-1] +a[i];
    }
    multiset<LL> st;
    for (int i=n;i>=1;i--)
    {
        suf[i] = suf[i+1] + a[i];
        st.insert(suf[i]);
    }
    LL mx = 0;
    for (int i=1;n>=i;i++)
    {
        st.erase(st.find(suf[i]));
        if (st.find(pre[i]) != st.end()) mx = pre[i];
    }
    printf("%lld\n",mx);
}