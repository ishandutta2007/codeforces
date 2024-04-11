#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<iostream>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
using std::cin;
using std::cout;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
typedef long double ldb;
ll n,k;
ll l,r;
ll ans=-1;
ll len;
int main()
{
	open("d");
	cin>>n>>l>>r>>k;
	len=(r>=l?r-l+1:n-l+1+r);
	if(n<=1000000)
	{
		for(int i=n;i<=2*n;i++)
		{
			ll s=k%i;
			if(s==0)
				s=i;
			s-=len;
			ll mi=max(i-n-(n-len)-1,0ll);
			ll ma=min(len,i-n);
			if(s>=mi&&s<=ma)
				ans=max(ans,i-n);
		}
	}
	else
	{
		if(k>=len&&k<=2*len)
			ans=max(ans,k==2*len?n:n-len+k-len+1);
		for(int i=1;i<=k/n;i++)
		{
			ll s2=min((k-2*len+2*n+1)/(i+1),(k-len)/i);
			ll s1=max((k-2*len+i-1)/i,(k-len+n+i)/(i+1));
			if(s1<=s2)
				ans=max(ans,s2-n);
		}
	}
	cout<<ans<<std::endl;
	return 0;
}