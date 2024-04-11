#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e5+3;
LL s[MAX];
LL f[2][MAX];
string a_1,a_2,b_1,b_2;
LL rin()
{
    LL s=0;
    char c=getchar();
    bool bj=0;
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')c=getchar(),bj=true;
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
int main()
{
    memset(f,0x3f,sizeof(f));
    int i,j;
    int n;
    n=rin();
    for(i=1;i<=n;i++)s[i]=rin();
    for(i=1;i<=n;i++)
    {
        cin>>a_1;a_2=a_1;
        std::reverse(a_2.rbegin(),a_2.rend());
        if(i==1)
        {
            f[0][i]=0;
            f[1][i]=s[i];
        }
        else
        {
            if(a_1>=b_1)f[0][i]=min(f[0][i],f[0][i-1]);
            if(a_2>=b_1)f[1][i]=min(f[1][i],f[0][i-1]+s[i]);
            if(a_1>=b_2)f[0][i]=min(f[0][i],f[1][i-1]);
            if(a_2>=b_2)f[1][i]=min(f[1][i],f[1][i-1]+s[i]);
        }
        b_1=a_1;b_2=a_2;
    }
    if(f[0][n]==0x3f3f3f3f3f3f3f3f&&f[1][n]==0x3f3f3f3f3f3f3f3f)printf("-1");
    else printf("%lld",min(f[0][n],f[1][n]));
    return 0;
}
//cd 
//g++ a+b.cpp -o a+b.exe
//./a+b.exe