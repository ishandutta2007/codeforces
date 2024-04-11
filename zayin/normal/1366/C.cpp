#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n,m;
int a[maxn][maxn];

map<int,int> cnt[maxn];
int tot[maxn];

int main()  {
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=0;i<maxn;++i) tot[i]=0,cnt[i].clear();
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)   {
                cin>>a[i][j];
                ++cnt[i+j][a[i][j]];
                ++tot[i+j];
            }
        
        int res=0;
        for (int i=0;2*i<(n-1)+(m-1);++i)   {
            map<int,int> mp=cnt[i];
            for (auto p:cnt[(n-1)+(m-1)-i])
                mp[p.first]+=p.second;
            int ans=0;
            for (auto p:mp)
                ans=max(ans,p.second);
            res+=2*tot[i]-ans;
        }

        cout<<res<<endl;
    }
    return 0;
}