#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,c[2][3];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                scanf("%d",&c[i][j]);
        int ans=0;
        int ct=min(c[0][2],c[1][1]);
        ans+=2*ct;
        c[0][2]-=ct,c[1][1]-=ct;
        ct=min(c[1][2],c[0][2]);
        c[1][2]-=ct,c[0][2]-=ct;
        ct=min(c[1][2],c[0][0]);
        c[1][2]-=ct,c[0][2]-=ct;
        ans-=2*c[1][2];
        printf("%d\n",ans);
    }
}