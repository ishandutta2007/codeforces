#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
//using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
char str[20000000];
int ccnt;
int rd(){int s=0,c,b=0;while(((c=str[++ccnt])<'0'||c>'9')&&c!='-');if(c=='-'){c=str[++ccnt];b=1;}do{s=s*10+c-'0';}while((c=str[++ccnt])>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int p=1000000007;
const int N=1<<17;
const int n=1<<17;
int f[N];
int plus(int a,int b){a+=b;return a>=p?a-p:a;}
int minus(int a,int b){a-=b;return a<0?a+p:a;}
ll fp(ll a,ll b)
{
	ll s=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1)
			s=s*a%p;
	return s;
}
int bitcount[N];
int m;
int a[N],b[N],c[N],d[N],e[N];
void fwt1(int *a)
{
	for(int i=0;i<n;i+=2)
		a[i+1]=plus(a[i+1],a[i]);
	for(int i=4;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<i/2;k+=2)
			{
				a[j+k+i/2]=plus(a[j+k+i/2],a[j+k]);
				a[j+k+i/2+1]=plus(a[j+k+i/2+1],a[j+k+1]);
			}
}
void fwt2(int *a)
{
	for(int i=0;i<n;i+=2)
		a[i+1]=minus(a[i+1],a[i]);
	for(int i=4;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<i/2;k+=2)
			{
				a[j+k+i/2]=minus(a[j+k+i/2],a[j+k]);
				a[j+k+i/2+1]=minus(a[j+k+i/2+1],a[j+k+1]);
			}
}
void fwt3(int *a)
{
	for(int i=2;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<i/2;k++)
			{
				int u=a[j+k];
				int v=a[j+k+i/2];
				a[j+k]=plus(u,v);
				a[j+k+i/2]=minus(u,v);
			}
}
void fwt4(int *a)
{
	for(int i=2;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<i/2;k++)
			{
				int u=a[j+k];
				int v=a[j+k+i/2];
				a[j+k]=plus(u,v);
				a[j+k+i/2]=minus(u,v);
			}
	ll inv=fp(fp(2,17),p-2);
	for(int i=0;i<n;i++)
		a[i]=a[i]*inv%p;
}
void fwt5(int *a)
{
	for(int i=2;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<i/2;k++)
				a[j+k]=plus(a[j+k],a[j+k+i/2]);
}
void fwt6(int *a)
{
	for(int i=2;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<i/2;k++)
				a[j+k]=minus(a[j+k],a[j+k+i/2]);
}
int a1[18][N],a2[18][N];
void gao1(int *a,int *b,int *c)//
{
	for(int i=0;i<n;i++)
		a1[bitcount[i]][i]=a[i];
	int len=bitcount[n-1];
	for(int i=0;i<=len;i++)
		fwt1(a1[i]);
	for(int i=len;i>=0;i--)
		for(int j=0;j<=i;j++)
			for(int k=0;k<n;k++)
				a2[i][k]=(a2[i][k]+(ll)a1[i-j][k]*a1[j][k])%p;
	for(int i=0;i<=len;i++)
		fwt2(a2[i]);
	for(int i=0;i<n;i++)
		c[i]=a2[bitcount[i]][i];
}
void gao2(int *a,int *b,int *c)//
{
	static int a1[N],a2[N];
	memcpy(a1,a,sizeof a1);
	memcpy(a2,b,sizeof a2);
	fwt3(a1);
	fwt3(a2);
	for(int i=0;i<n;i++)
		a1[i]=(ll)a1[i]*a2[i]%p;
	fwt4(a1);
	memcpy(c,a1,sizeof a1);
}
void gao3(int *a,int *b,int *c)// 
{
	static int a1[N],a2[N];
	memcpy(a1,a,sizeof a1);
	memcpy(a2,b,sizeof a2);
	fwt5(a1);
	fwt5(a2);
	for(int i=0;i<n;i++)
		a1[i]=(ll)a1[i]*a2[i]%p;
	fwt6(a1);
	memcpy(c,a1,sizeof a1);
}
int main()
{
	open("cf914g");
	fread(str+1,20000000,1,stdin);
	m=rd();
	int x;
	for(int i=1;i<=m;i++)
	{
		x=rd();
		a[x]++;
	}
	for(int i=1;i<n;i++)
		bitcount[i]=bitcount[i>>1]+(i&1);
	f[1]=1;
	for(int i=2;i<n;i++)
		f[i]=(f[i-2]+f[i-1])%p;
	gao1(a,a,b);
	gao2(a,a,c);
	for(int i=0;i<n;i++)
		a[i]=(ll)a[i]*f[i]%p;
	for(int i=0;i<n;i++)
		b[i]=(ll)b[i]*f[i]%p;
	for(int i=0;i<n;i++)
		c[i]=(ll)c[i]*f[i]%p;
	gao3(a,b,d);
	gao3(c,d,e);
	int ans=0;
	for(int i=1;i<n;i<<=1)
		ans=(ans+e[i])%p;
	ans=(ans+p)%p;
	printf("%d\n",ans);
}