#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define PI 3.14159265358979323846
struct complex
{
	long double real,imag;
	complex(long double r=0,long double i=0):real(r),imag(i){}
};
inline complex operator+(complex x,complex y){return complex(x.real+y.real,x.imag+y.imag);}
inline complex operator-(complex x,complex y){return complex(x.real-y.real,x.imag-y.imag);}
inline complex operator*(complex x,complex y){return complex(x.real*y.real-x.imag*y.imag,x.real*y.imag+x.imag*y.real);}
inline complex conj(complex x){return complex(x.real,-x.imag);}
struct node
{
	complex a[1048576];
	void fft(int);
}A,B,G,H;int len;
int r[1048576];
complex w[1048576];
void node::fft(int type)
{
	for(int i=0;i<len;i++)if(i<r[i])swap(a[i],a[r[i]]);
	w[0]=complex(1);
	for(int i=1;i<len;i<<=1)
	{
		complex wi(cos(PI/i),type*sin(PI/i));
		for(int j=i-2;j>=0;j-=2)w[j]=w[j>>1];
		for(int j=1;j<i;j+=2)w[j]=w[j-1]*wi;
		for(int j=0;j<len;j+=i<<1)
		{
			for(int k=0;k<i;k++)
			{
				complex ak=a[j+k],awk=w[k]*a[i+j+k];
				a[j+k]=ak+awk;
				a[i+j+k]=ak-awk;
			}
		}
	}
}
const int mod=998244353,mmod=31595;
inline long long ksm(long long x,long long k)
{
	long long s=1;
	while(k>0)
	{
		if(k&1)s=s*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return s;
}
long long jc[610000],fjc[610000];
inline long long C(long long m,long long n){return n>m?0:jc[m]*fjc[m-n]%mod*fjc[n]%mod;}
int a[310000],b[6];
int cnt[310000];
int F[6][610000];
int main()
{
	jc[0]=1;
	for(int i=1;i<=600000;i++)jc[i]=jc[i-1]*i%mod;
	fjc[600000]=ksm(jc[600000],mod-2);
	for(int i=599999;i>=0;i--)fjc[i]=fjc[i+1]*(i+1)%mod;
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=n;j++)
		{
			if(a[j]<b[i])cnt[a[j]]++;
		}
		int c1=0,c2=0;
		for(int j=1;j<=300000;j++)
		{
			if(cnt[j]>=2)c2++;
			else if(cnt[j]==1)c1++;
		}
		if(c1==0&&c2==0){F[i][0]=1;continue;}
		len=1;int t=-1;
		while(len<=c1+c2*2)len<<=1,t++;
		r[0]=0;
		for(int j=1;j<len;j++)r[j]=r[j>>1]>>1|(j&1)<<t;
		for(int j=0;j<len;j++)
		{
			long long x1=ksm(2,j)*C(c1,j)%mod,x2=C(c2*2,j);
			long long a=x1/mmod,b=x1%mmod,g=x2/mmod,h=x2%mmod;
			A.a[j]=complex(a,b);G.a[j]=complex(g,h);
		}
		A.fft(1);G.fft(1);
		B.a[0]=conj(A.a[0]);
		H.a[0]=conj(G.a[0]);
		for(int j=1;j<len;j++)
		{
			B.a[j]=conj(A.a[len-j]);
			H.a[j]=conj(G.a[len-j]);
		}
		for(int j=0;j<len;j++)
		{
			complex a=A.a[j],b=B.a[j],g=G.a[j],h=H.a[j];
			A.a[j]=complex((a.real+b.real)/2,(a.imag+b.imag)/2);
			B.a[j]=complex((a.imag-b.imag)/2,(b.real-a.real)/2);
			G.a[j]=complex((g.real+h.real)/2,(g.imag+h.imag)/2);
			H.a[j]=complex((g.imag-h.imag)/2,(h.real-g.real)/2);
		}
		for(int j=0;j<len;j++)
		{
			complex a=A.a[j],b=B.a[j],g=G.a[j],h=H.a[j];
			A.a[j]=a*g+b*h*complex(0,1);
			G.a[j]=a*h+b*g;
		}
		A.fft(-1);G.fft(-1);
		for(int j=0;j<len;j++)
		{
			long long af=A.a[j].real/len+0.5,bf=A.a[j].imag/len+0.5,cf=G.a[j].real/len+0.5;
			F[i][j]=(af%mod*mmod*mmod%mod+bf%mod+cf*mmod%mod)%mod;
		}
	}
	int t;scanf("%d",&t);
	while(t--)
	{
		int Q;scanf("%d",&Q);Q=Q/2;
		int ss=0;
		for(int i=1;i<=m;i++)
		{
			ss=(ss+F[i][Q-b[i]-1])%mod;
		}
		printf("%d\n",ss);
	}
	return 0;
}