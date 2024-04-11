#include<bits/stdc++.h>
#define maxn 700050
using namespace std;
typedef long long LL;

int n,a[maxn];

char s[maxn];

map<int,int> cnt;

int stk[maxn],tp;

int get()
{
    scanf("%s",s);
    tp=0;
    for (int i=0;s[i];++i)
    {
        if (s[i]=='(')
            stk[++tp]=i;
        else
        {
            if (tp&&s[stk[tp]]=='(')    --tp;
            else
                stk[++tp]=i;
        }
    }

    bool L=1,R=1;
    for (int i=1;i<=tp;++i)
        L&=s[stk[i]]=='(',R&=s[stk[i]]==')';
    if (L)  return tp;
    if (R)  return -tp;
    return maxn;
}

int main()
{
    int ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;++i)
    {
        int t=get();

        // cout<<i<<" "<<t<<" "<<cnt[-t]<<endl;
        if (cnt[-t])
            ++ans,--cnt[-t];
        else
            ++cnt[t];
    }
    printf("%d\n",ans);
    return 0;
}