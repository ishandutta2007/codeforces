#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    vector<int> cnt(n+1,0);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),++cnt[a[i]];
    int all_mex=0;
    for(int i=0;i<=n;i++)
        if(!cnt[i])
        {
            all_mex=i;
            break;
        }
    vector<int> res;
    int now_mex=0;
    vector<int> cnt_now(n+1,0);
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=l || (r<=n && now_mex<all_mex))
        {
            ++cnt_now[a[r]],r++;
            while(cnt_now[now_mex])++now_mex;
        }
        res.push_back(now_mex);
        now_mex=0;
        for(int i=l;i<r;i++)
            --cnt_now[a[i]];
        for(int i=l;i<r;i++)
            if(--cnt[a[i]]==0)
                all_mex=min(all_mex,a[i]);
    }
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d%c",res[i]," \n"[i+1==(int)res.size()]);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}