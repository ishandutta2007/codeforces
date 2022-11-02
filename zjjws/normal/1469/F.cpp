#include <algorithm>
#include <stdio.h>
#pragma GCC optimize(2)
#define LL long long
using namespace std;
const int N=4e5+3;
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

int n,k;
int l[N];
int s[N<<1];
inline bool myru_l(int x,int y){return x>y;}
int main()
{
    int i,j;
    n=rin();k=rin();
    for(i=1;i<=n;i++)l[i]=rin();
    sort(l+1,l+n+1,myru_l);
    s[0]=1;s[1]=-1;
    LL sum=0;
    int ans=0x3f3f3f3f;
    for(i=0,j=1;i<N;i++)
    {
        sum+=s[i];
        s[i+1]+=s[i];
        if(sum+s[i+1]>=k){ans=i+1;break;}
        for(;j<=n&&s[i];j++)
        {
            s[i+2]+=2;
            s[i+2+(l[j]-1>>1)]--;
            s[i+2+(l[j]-1-(l[j]-1>>1))]--;
            s[i]--;
            sum--;
        }
    }
    //El Psy Congroo
    //O ha ha ha ha
    printf("%d\n",(ans==0x3f3f3f3f)?(-1):(ans));
    return 0;
}