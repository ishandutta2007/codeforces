#include<bits/stdc++.h>
using namespace std;
const int MAXN=250005;
int a[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    vector<int> go(n+1);
    vector<int> mx,mi;
    mx.push_back(n+1);
    mi.push_back(n+1);
    for(int i=n;i>=1;i--)
    {
        while(mx.size()>1u && a[mx.back()]<a[i])mx.pop_back();
        while(mi.size()>1u && a[mi.back()]>a[i])mi.pop_back();
        if(i<n)
        {
            if(mx.back()>mi.back())go[i]=*upper_bound(mi.begin(),mi.end(),mx.back(),greater<int>());
            else go[i]=*upper_bound(mx.begin(),mx.end(),mi.back(),greater<int>());
        }
        mx.push_back(i);
        mi.push_back(i);
    }
    int res=0,cur=1;
    while(cur<n)cur=go[cur],res++;
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}