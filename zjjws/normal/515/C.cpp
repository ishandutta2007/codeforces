#include <bits/stdc++.h>
#define LL long long
#define jh(a,b) a^=b^=a^=b
using namespace std;
const int N=15;
int ans[N];
int n;
LL a;
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
    int i,j;
    n=rin();a=rin();
    //2->2
    //3->3
    //4->322
    //5->5
    //6->532
    //7->7
    //8->7222
    //9->7332
    for(;a>0;a/=10)
    {
        int now=a%10;
        if(now==2)ans[2]++;
        if(now==3)ans[3]++;
        if(now==4)ans[2]+=2,ans[3]++;
        if(now==5)ans[5]++;
        if(now==6)ans[3]++,ans[5]++;
        if(now==7)ans[7]++;
        if(now==8)ans[7]++,ans[2]+=3;
        if(now==9)ans[2]++,ans[3]+=2,ans[7]++;
    }
    for(i=9;i>=2;i--)for(j=ans[i];j>0;j--)printf("%d",i);
    return 0;
}