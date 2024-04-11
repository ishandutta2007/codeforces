#include<bits/stdc++.h>
using namespace std;

const int N=57;

int T;

int n,m;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        vector<int>v;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                v.push_back(max({i-1+j-1,n-i+j-1,i-1+m-j,n-i+m-j}));
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            printf("%d ",v[i]);
        puts("");
    }
}