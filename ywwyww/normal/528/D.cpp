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
int upmin(int &a,int b)
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
struct cp
{
	double x,y;
	cp(double a=0,double b=0)
	{
		x=a;
		y=b;
	}
};
cp operator +(cp a,cp b){return cp(a.x+b.x,a.y+b.y);}
cp operator -(cp a,cp b){return cp(a.x-b.x,a.y-b.y);}
cp operator *(cp a,cp b){return cp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
cp operator /(cp a,double b){return cp(a.x/b,a.y/b);}
cp a[1100010];
cp b[1100010];
char s[200010];
char t[200010];
int n,m,k;
int c[5][400010];
int get(char c)
{
	if(c=='A')
		return 1;
	if(c=='C')
		return 2;
	if(c=='G')
		return 3;
	if(c=='T')
		return 4;
	return 0;
}
int sum[400010];
int len;
int rev[1100010];
cp w1[1100010];
cp w2[1100010];
double pi=acos(-1);
void init(int n)
{
	len=1;
	while(len<=2*n)
		len<<=1;
	int i;
	for(i=1;i<=len;i<<=1)
	{
		w1[i]=cp(cos(2*pi/i),sin(2*pi/i));
		w2[i]=cp(w1[i].x,-w1[i].y);
	}
	rev[0]=0;
	for(i=1;i<len;i++)
		rev[i]=(rev[i>>1]>>1)|(i&1?len>>1:0);
}
void fft(cp *a,int t)
{
	cp w,wn,u,v;
	int i,j,k;
	for(i=0;i<len;i++)
		if(rev[i]<i)
			swap(a[i],a[rev[i]]);
	for(i=1;i<=len;i<<=1)
	{
		wn=(t==1?w1[i]:w2[i]);
		for(j=0;j<len;j+=i)
		{
			w=cp(1);
			for(k=j;k<j+i/2;k++)
			{
				u=a[k];
				v=a[k+i/2]*w;
				a[k]=u+v;
				a[k+i/2]=u-v;
				w=w*wn;
			}
		}
	}
	if(t==-1)
		for(i=0;i<len;i++)
			a[i]=a[i]/len;
}
void solve(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(get(s[i])==x)
			sum[i]=1;
		else
			sum[i]=0;
		sum[i]+=sum[i-1];
	}
	int l,r;
	for(i=0;i<len;i++)
		a[i]=b[i]=cp();
	for(i=1;i<=n;i++)
	{
		l=max(1,i-k);
		r=min(n,i+k);
		if(sum[r]-sum[l-1])
			a[i]=cp(1);
	}
	for(i=1;i<=m;i++)
		if(get(t[i])==x)
			b[i]=cp(1);
	reverse(b+1,b+m+1);
	fft(a,1);
	fft(b,1);
	for(i=0;i<len;i++)
		a[i]=a[i]*b[i];
	fft(a,-1);
	for(i=1;i<=n+m;i++)
		c[x][i]=round(a[i].x);
}
int main()
{
	open("cf528d");
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s+1,t+1);
	init(n+m);
	solve(1);
	solve(2);
	solve(3);
	solve(4);
	int ans=0;
	int i;
	for(i=m+1;i<=n+1;i++)
		if(c[1][i]+c[2][i]+c[3][i]+c[4][i]==m)
			ans++;
	printf("%d\n",ans);
	return 0;
}