#include<bits/stdc++.h>
#define maxn 505
using namespace std;
typedef long long LL;

int n;

char mp[maxn][maxn];

const int d[5][2]={{0,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%s",mp[i]+1);
    
    int cnt=0;
    for (int i=2;i<n;++i)
        for (int j=2;j<n;++j)
        {
            bool flag=1;
            for (int k=0;k<5;++k)
                flag&=mp[i+d[k][0]][j+d[k][1]]=='X';
            // cout<<i<<" "<<j<<" "<<flag<<endl;
            if (flag)
                ++cnt;
        }
    printf("%d\n",cnt);
    return 0;
}