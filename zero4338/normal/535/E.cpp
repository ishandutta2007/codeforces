#include<iostream>
#include<cstdio>
#include<algorithm> 
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=3e5+5;
const double eps=1e-30;
int n;
struct point
{
    double x,y;int num;
    const bool operator <(const point &a)const{if(x!=a.x)return x>a.x;return y>a.y;}
    const bool operator ==(const point &a)const{return x==a.x&&y==a.y;}
    friend bool judge(point a,point b,point c){return c.x*a.y*(a.x-b.x)*(b.y-c.y)<c.y*a.x*(a.y-b.y)*(b.x-c.x);}
}p[maxn];
bool used[maxn];int sta[maxn],top;
int ans[maxn],cnt;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)p[i].x=read(),p[i].y=read(),p[i].num=i;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    {
        if(top&&p[sta[top]]==p[i])continue;
        if(top&&p[i].y<=p[sta[top]].y)continue;
        while(top>=2&&judge(p[sta[top-1]],p[sta[top]],p[i]))used[sta[top--]]=0;
        used[sta[++top]=i]=1;
    }
    for(int i=2;i<=n;i++)
        if(p[i]==p[i-1]&&used[i-1])used[i]=1;
    for(int i=1;i<=n;i++)if(used[i])ans[++cnt]=p[i].num;
    sort(ans+1,ans+cnt+1);
    for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
    return 0;
}