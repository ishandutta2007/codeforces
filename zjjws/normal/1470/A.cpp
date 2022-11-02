#include <stdio.h>
#include <queue>
#define LL long long
using namespace std;
const int N=3e5+3;
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


int a[N];
int b[N];
struct gyq
{
    int val,num;
    gyq(int val_=0,int num_=0){val=val_;num=num_;}
};
inline bool operator <(gyq x,gyq y){return x.val<y.val;}
inline bool operator >(gyq x,gyq y){return x.val>y.val;}
priority_queue<gyq,vector<gyq>,greater<gyq> >q;
inline void work()
{
    int n=rin(),m=rin();
    for(int i=1;i<=n;i++)a[rin()]++;
    for(int i=1;i<=m;i++)b[i]=rin(),q.push(gyq(b[i],i));
    LL ans=0;
    for(int i=m;i>=1;i--)
    {
        for(;a[i]&&!q.empty();)
        {
            if(q.top().num>i){q.pop();continue;}
            if(q.top().val>=b[i])break;
            ans+=q.top().val;
            q.pop();
            a[i]--;
        }
        ans+=1LL*b[i]*a[i];
        a[i]=0;
    }
    for(;!q.empty();q.pop());
    printf("%lld\n",ans);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}