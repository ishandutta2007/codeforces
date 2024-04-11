#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,m;

int a[N],b[N];

vector<int>v[2];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        v[0].clear();
        v[1].clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
            v[b[i]-1].push_back(a[i]);
        for(int i=0;i<2;i++)
            sort(v[i].begin(),v[i].end()),reverse(v[i].begin(),v[i].end());
        long long s1=0,s2=0;
        for(auto x:v[1])
            s2+=x;
        int ans=0x7fffffff;
        int j=(int)v[1].size()-1;
        while(j>=0&&s2-v[1][j]+s1>=m)
            s2-=v[1][j],j--;
        if(s2>=m)
            ans=min(ans,(j+1)*2);
        for(int i=0;i<v[0].size();i++)
        {
            s1+=v[0][i];
            while(j>=0&&s2-v[1][j]+s1>=m)
                s2-=v[1][j],j--;
            if(s1+s2>=m)
                ans=min(ans,(i+1)+(j+1)*2);
        }
        printf("%d\n",ans==0x7fffffff?-1:ans);
    }
}