#include <bits/stdc++.h>
using namespace std;

int a[1234];
int b[1234];

int main ()
{
    int n,k1,k2;
    scanf("%d %d %d",&n,&k1,&k2);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    multiset<int> st;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&b[i]);
        st.insert(abs(a[i]-b[i]));
    }
    int cnt = k1 + k2;
    while (cnt--)
    {
        int _ = *prev(st.end());
        st.erase(st.find(_));
        if (!_) ++_;
        else --_;
        st.insert(_);
    }
    long long ans=0;
    for (int i:st)
    {
        ans += i*1LL*i;
    }
    printf("%lld\n",ans);
}