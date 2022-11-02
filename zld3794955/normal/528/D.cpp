#include<bits/stdc++.h>
using namespace std;
const double eps(1e-6);
const double pi(3.14159265358979);
const int L=200020,N=550000,M=N;
const char ch[4]={'A','C','G','T'};
char S[L]={},T[L]={};
int n,m,k,s[N]={};
bool bad[N]={};
struct mycomplex
{
	double real,imag;
}a[N]={},b[N]={};
inline mycomplex operator +(const mycomplex &a,const mycomplex &b)
{
	return (mycomplex){a.real+b.real , a.imag+b.imag};
}
inline mycomplex operator -(const mycomplex &a,const mycomplex &b)
{
	return (mycomplex){a.real-b.real , a.imag-b.imag};
}
inline mycomplex operator *(const mycomplex &a,const mycomplex &b)
{
	return (mycomplex){a.real*b.real-a.imag*b.imag , a.real*b.imag+a.imag*b.real};
}
struct FFT_transform
{
	int n,l;
	double e;
	void setl(int len)
	{
		for(l=0; (1<<l)<len*2;++l)
			;
		n=1<<l;
		e=2*pi/n;
	}
	int rebit(int x)
	{
		int y=0;
		for(int i=0;i<l;++i)
			y|=bool(x&(1<<i)) * (1<<(l-i-1));
		return y;
	}
	void DFT_inplace(mycomplex *t,int sign)
	{
		for(int i=0;i<n;++i)
			if(i<rebit(i))
				swap(t[i],t[rebit(i)]);
		for(int i=1;i<=l;++i)
		{
			int d=(1<<i);
			double tmp=(sign==1 ? e : -e)*(1<<(l-i));
			mycomplex g1 =(mycomplex){cos(tmp),sin(tmp)};
			for(int j=0;j<n;j+=d)
			{
				mycomplex w =(mycomplex){1,0};
				for(int k=j;k<j+d/2;++k)
				{
					mycomplex t1=t[k],t2=t[k+d/2]*w;
					t[k]=t1+t2;
					t[k+d/2]=t1-t2;
					w=w*g1;
				}
			}
		}
	}
	void FFT(mycomplex *a,mycomplex *b)
	{
		DFT_inplace(a,1);
		DFT_inplace(b,1);
		for(int i=0;i<n;++i)
			a[i]=a[i]*b[i];
		DFT_inplace(a,-1);
		for(int i=0;i<n;++i)
			a[i].real=a[i].real/n;
	}
};
int main()
{	
	int Test=1;
	FFT_transform calc;
	//scanf("%d",&Test);
	while(Test--)
	{
		scanf("%d %d %d\n%s\n%s",&n,&m,&k,S+1,T+1);
		calc.setl(n);
		for(int i=0;i<n;++i)
			bad[i]=false;
		for(int j=0;j<4;++j)
		{
			fill(a,a+N,(mycomplex){0,0});
			fill(b,b+N,(mycomplex){0,0});
			for(int i=1;i<=n;++i)
				s[i]=s[i-1]+(S[i]==ch[j]);
			for(int i=1;i<=n;++i)
				a[i-1].real=(s[min(n,i+k)]-s[max(0,i-k-1)]>0);
			long long t=0;
			for(int i=1;i<=m;++i)
				if(T[i]==ch[j])
					++t,b[m-i].real=1;
			calc.FFT(a,b);
			for(int i=0;i<n;++i)
				bad[i]|=fabs(a[i+m-1].real-t)>eps;
		}
		int ans=0;
		for(int i=0;i<n;++i)
			ans+=!bad[i];
		cout<<ans<<endl;
	}
	return 0;
}