#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
    if(a>b)
        swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
    char str[100];
    sprintf(str,"%s.in",s);
    freopen(str,"r",stdin);
    sprintf(str,"%s.out",s);
    freopen(str,"w",stdout);
#endif
}
int rd()
{
    int s=0,c;
    while((c=getchar())<'0'||c>'9');
    do
    {
        s=s*10+c-'0';
    }
    while((c=getchar())>='0'&&c<='9');
    return s;
}
int upmin(ll &a,ll b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
ll s1[2000010];
ll s2[2000010];
void add(int l,int r,int x,int y)
{
    s1[l]+=x;
    s1[r+1]-=x;
    s2[l]+=y;
    s2[r+1]-=y;
}
int a[2000010];
int main()
{
    open("c");
    int n;
    scanf("%d",&n);
    int i;
    memset(s1,0,sizeof s1);
    memset(s2,0,sizeof s2);
    for(i=1;i<=n;i++)
    {
        a[i]=rd();
        if(a[i]<i)
        {
            add(0,n-i,1,i-a[i]);//i-a[i]
            add(n-i+1,a[i]+n-i,-1,a[i]+n-i);//-i+a[i]
            add(a[i]+n-i+1,n-1,1,-a[i]-n+i);//i-a[i]
        }
        else
        {
            add(0,a[i]-i,-1,a[i]-i);//-i+a[i]
            add(a[i]-i+1,n-i,1,i-a[i]);//i-a[i]
            add(n-i+1,n-1,-1,a[i]+n-i);//-i+a[i]
        }
    }
    ll ans=0x7fffffffffffffffll;
    int orzzjt;
    for(i=1;i<=n;i++)
    {
        s1[i]+=s1[i-1];
        s2[i]+=s2[i-1];
    }
    for(i=0;i<n;i++)
        if(upmin(ans,s1[i]*i+s2[i]))
        	orzzjt=i;
    printf("%I64d %d\n",ans,orzzjt);
    return 0;
}