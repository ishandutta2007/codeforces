#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define M_PI 3.14159265358979323846
struct complex
{
	double real,imag;
	complex(double r=0,double i=0):real(r),imag(i){}
};
inline complex operator+(complex x,complex y){return complex(x.real+y.real,x.imag+y.imag);}
inline complex operator-(complex x,complex y){return complex(x.real-y.real,x.imag-y.imag);}
inline complex operator*(complex x,complex y){return complex(x.real*y.real-x.imag*y.imag,x.real*y.imag+x.imag*y.real);}
inline complex conj(complex x){return complex(x.real,-x.imag);}
struct py
{
	complex a[65536];
	void fft();
}A,B,a,b,c,d;int len;
complex w[65536];
int r[65536];
void py::fft()
{
	for(int i=0;i<len;i++)if(i<r[i])swap(a[i],a[r[i]]);
	w[0]=1;
	for(int i=2;i<=len;i<<=1)
	{
		complex wi(cos(2*M_PI/i),sin(2*M_PI/i));
		for(int j=(i>>1)-2;j>=0;j-=2)w[j]=w[j>>1];
		for(int j=1;j<i>>1;j+=2)w[j]=w[j-1]*wi;
		for(int j=0;j<len;j+=i)
		{
			for(int k=0;k<i>>1;k++)
			{
				complex a1=a[j+k],a2=w[k]*a[j+(i>>1)+k];
				a[j+k]=a1+a2;a[j+(i>>1)+k]=a1-a2;
			}
		}
	}
}
struct node
{
	long long a[65536];
}f,g,gg;const int p=1000000007;
node operator*(node x,node y)
{
	node z;
	for(int i=0;i<len;i++)A.a[i]=complex(x.a[i]&32767,x.a[i]>>15);
	for(int i=0;i<len;i++)B.a[i]=complex(y.a[i]&32767,y.a[i]>>15);
	A.fft();B.fft();
	for(int i=0;i<len;i++)
	{
		int j=(len-i)&(len-1);
		complex ad,bd,cd,dd;
		ad=(A.a[i]+conj(A.a[j]))*complex(0.5,0);
		bd=(A.a[i]-conj(A.a[j]))*complex(0,-0.5);
		cd=(B.a[i]+conj(B.a[j]))*complex(0.5,0);
		dd=(B.a[i]-conj(B.a[j]))*complex(0,-0.5);
		a.a[j]=ad*cd;b.a[j]=ad*dd;c.a[j]=bd*cd;d.a[j]=bd*dd;
	}
	for(int i=0;i<len;i++)A.a[i]=a.a[i]+b.a[i]*complex(0,1);
	for(int i=0;i<len;i++)B.a[i]=c.a[i]+d.a[i]*complex(0,1);
	A.fft();B.fft();
	for(int i=0;i<len;i++)
	{
		long long ad,bd,cd,dd;
		ad=(long long)(A.a[i].real/len+0.5)%p;
		bd=(long long)(A.a[i].imag/len+0.5)%p;
		cd=(long long)(B.a[i].real/len+0.5)%p;
		dd=(long long)(B.a[i].imag/len+0.5)%p;
		z.a[i]=(ad+((bd+cd)<<15)+(dd<<30))%p;
	}
	return z;
}
long long ksm(long long x,long long k)
{
	long long s=1;
	while(k)
	{
		if(k&1)s=s*x%p;
		x=x*x%p;
		k>>=1;
	}
	return s;
}
long long jc[30001],fjc[30001];
int main()
{
	long long n,m;scanf("%lld%lld",&n,&m);
	if(n>m)
	{
		puts("0");
		return 0;
	}
	len=1;int np=-1;
	while(len<=m*2)len<<=1,np++;
	r[0]=0;
	for(int i=0;i<len;i++)r[i]=r[i>>1]>>1|(i&1)<<np;
	jc[0]=1;
	for(int i=1;i<=m;i++)jc[i]=jc[i-1]*i%p;
	fjc[m]=ksm(jc[m],p-2);
	for(int i=m-1;i>=0;i--)fjc[i]=fjc[i+1]*(i+1)%p;
	f.a[0]=1;
	for(int i=1;i<=m;i++)g.a[i]=fjc[i];
	long long y2y=2;
	while(n)
	{
		if(n&1)
		{
			int yj=1;
			for(int i=0;i<=m;i++,yj=yj*y2y%p)f.a[i]=f.a[i]*yj%p;
			f=f*g;
			for(int i=m+1;i<len;i++)f.a[i]=0;
		}
		long long yj=1;
		for(int i=0;i<=m;i++,yj=yj*y2y%p)gg.a[i]=g.a[i]*yj%p;
		for(int i=m+1;i<len;i++)gg.a[i]=0;
		g=gg*g;
		for(int i=m+1;i<len;i++)g.a[i]=0;
		y2y=y2y*y2y%p;
		n>>=1;
	}
	long long ss=0;
	for(int i=0;i<=m;i++)ss=(ss+f.a[i]*jc[m]%p*fjc[m-i]%p)%p;
	printf("%lld\n",ss);
	return 0;
}