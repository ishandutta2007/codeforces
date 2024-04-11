#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int ta[MAXN];
int a[MAXN],pre[MAXN];
int cnt[MAXN][23];
vector<int> cur[(1<<20)+3];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&ta[i]);
    int res=0;
    for(int _=19;_>=0;_--)
    {
        for(int i=1;i<=n;i++)
            a[i]=(ta[i]>>_),pre[i]=pre[i-1]^a[i];
        for(int i=0;i<(1<<(20-_));i++)
            cur[i].clear();
        for(int i=0;i<=n;i++)
            cur[pre[i]].push_back(i);
        for(int i=1;i<=n;i++)
            for(int j=0;j<20-_;j++)
                cnt[i][j]=cnt[i-1][j]+(a[i]>>j&1);
        auto check = [&] (int l,int r) {
            for(int i=0;i<20-_;i++)
                if(cnt[r][i]-cnt[l-1][i]==r-l+1) return 1;
            return 0;
        };
        for(int l=1,r=1;r<=n;r++)
        {
            while(l<=r && !check(l,r))l++;
            if(l<=r && r-l+1>=res){
                auto itr=lower_bound(cur[pre[r]].begin(),cur[pre[r]].end(),l-1);
                if(itr!=cur[pre[r]].end())res=max(res,r-*itr);
            }
        }
    }
    return 0*printf("%d\n",res);
}