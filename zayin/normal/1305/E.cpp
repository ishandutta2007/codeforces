#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n,m;
int f[maxn];

vector<int> ans;

int main()  {
    for (int i=3;i<maxn;++i)
        f[i]=f[i-1]+(i-1)/2;
    // for (int i=1;i<=20;++i) cout<<i<<":"<<f[i]<<endl;
    
    scanf("%d%d",&n,&m);
    if (f[n]<m)
        puts("-1");
    else    {
        int _n=0;
        for (;_n<n&&f[_n+1]<=m;++_n);
        
        for (int i=1;i<=_n;++i)
            ans.push_back(i);
        m-=f[_n];
        if (m)  {
            for (int i=_n+1;i<_n+_n;++i) {
                int j=i-_n;
                if ((_n-j+1)/2==m)   {
                    ans.push_back(i);
                    break;
                }
            }
            assert(ans.size()>_n);
        }

        // cout<<"f:"<<f[_n]<<endl;
        
        n-=ans.size();
        int lim=1e9,step=ans.back()+1;

        assert(n>=0);
        while (n--)
            ans.push_back(lim),lim-=step;
        
        sort(ans.begin(),ans.end());
        for (int i:ans)
            printf("%d ",i);
    }
    return 0;
}