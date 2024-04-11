#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x!=y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n;

const int INF=1e9+7;
inline LL ksm(LL x,int y)
{
    LL ans=1;
    bool tag=false;
    if(y==2&&x==998)tag=true;
    for(;y;y>>=1)
    {
        if(x>INF)return x;
        // if(tag)printf("x:%lld y:%d ans:%lld\n",x,y,ans);
        if(y&1)
        {
            ans=ans*x;
            // if(tag)printf("x:%lld y:%d ans:%lld\n",x,y,ans);
            if(ans>INF)return ans;
        }
        x=x*x;
    }
    return ans;
}
inline void work()
{
    LL a=rin(),b=rin();
    LL ans=0;
    LL sum=0x3f3f3f3f;
    if(b==1)ans++,b++;
    for(;true;ans++,b++)
    {
        int l=1,r=30;
        int lst;
        for(;l<=r;)
        {
            int mid=l+r>>1;
            // printf("ksm %d %d:%lld\n",b,mid,ksm(b,mid));
            if(ksm(b,mid)>a)lst=mid,r=mid-1;
            else l=mid+1;
        }
        // printf("b:%d lst:%d\n",b,lst);
        sum=min(sum,ans+lst);
        if(ans+lst>sum)break;
    }
    for(int i=1;i<=100;i++)
    {
        int l=1,r=30;
        int lst;
        for(;l<=r;)
        {
            int mid=l+r>>1;
            if(ksm(b,mid)>a)lst=mid,r=mid-1;
            else l=mid+1;
        }
        sum=min(sum,ans+lst);
        ans++;b++;
    }
    printf("%lld\n",sum);
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}