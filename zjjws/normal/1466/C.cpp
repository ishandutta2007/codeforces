#include <stdio.h>
#include <string>
#include <iostream>
#define LL long long
using namespace std;
const int N=1e5+3;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}

int n;
int f[27][N];
int a[N];
string x;
inline void work()
{
    x.clear();
    cin>>x;n=x.length();
    // a[1]=x[0]-'a';
    // for(int j=0;j<26;j++)f[j][1]=(a[1]!=j);
    // for(int i=2;i<=n;i++)
    // {
    //     a[i]=x[i-1]-'a';
    //     if(i==2)
    //     {
    //         for(int j=0;j<26;j++)
    //         {
    //             f[j][i]=0x3f3f3f3f;
    //             for(int k=0;k<26;k++)if(j!=k)f[j][i]=min(f[j][i],f[k][i-1]);
    //             f[j][i]+=(j!=a[i]);
    //         }
    //     }
    //     else
    //     {
    //         for(int j=0;j<26;j++)
    //         {
    //             f[j][i]=0x3f3f3f3f;
    //             for(int k=0;k<26;k++)if(j!=k)f[j][i]=min(f[j][i],f[k][i-2]+(k==a[i-1]||j==a[i-1]));
    //             f[j][i]+=(j!=a[i]);
    //         }
    //     }
    // }
    // int ans=0x3f3f3f3f;
    // for(int i=0;i<26;i++)ans=min(ans,f[i][n]);

    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(x[i]==x[i-1]||(i>1&&x[i]==x[i-2]))
        {
            for(char j='a';j<='z';j++)if(j!=x[i-1]&&(j==1||j!=x[i-2])&&j!=x[i+1]&&j!=x[i+2]){x[i]=j;break;}
            ans++;
        }
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}