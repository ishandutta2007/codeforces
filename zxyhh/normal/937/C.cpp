#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define PC Putchar
#define GC getchar
#define ll long long
#define ldb long double
#define pii pair<int,int>
#define pdd pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb push_back
#define VI vector<int>
#define VS vector<string>
using namespace std;
    inline ll rd(){
	    ll x=0;int ch=GC(); bool f=1;
	    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=GC();
	    if (ch=='-'){f=0;ch=GC();}
	    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=GC();}
	    return f?x:-x;
    }
ll k,d,t;
double ans;
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	k=rd(),d=rd(),t=rd()*2;
	ll p=k/d;
	if (d*p<k) p++;
	ll sum=d*p,q=t/(k*2+(d*p-k));
	ans=sum*q;t%=k*2+(d*p-k);
	if (t<=k*2) ans+=t/2.0;
	else ans+=k+(t-k*2);
	printf("%.2lf",ans);
	return 0;
}