#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#include <complex>
#define SIZE 500005
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef complex <double> C;
const C I(0,1);

struct FFT
{
	vector <C> fft(int n, double theta, vector <C> a)
	{
		for (int m = n; m >= 2; m >>= 1)
		{
			int mh = m >> 1;
			for (int i = 0; i < mh; i++)
			{
				C w = exp(i*theta*I);
				for (int j = i; j < n; j += m)
				{
					int k = j + mh;
					C x = a[j] - a[k];
					a[j] += a[k];
					a[k] = w * x;
				}
			}
			theta *= 2;
		}
		int i = 0;
		for (int j = 1; j < n - 1; j++)
		{
			for (int k = n >> 1; k > (i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}
		return a;
	}
	vector <int> getFFT(vector <int> A,vector <int> B)
	{
		vector <C> x,b;
		for(int i=0;i<A.size()+B.size();i++)
		{
			x.push_back(C(i<A.size()?A[i]:0,0));
			b.push_back(C(i<B.size()?B[i]:0,0));
		}
		int N=1;
		while(N<x.size()) N<<=1;
		while(x.size()<N) x.push_back(C(0,0)),b.push_back(C(0,0));
		x=fft(N,2*PI/N,x);
		b=fft(N,2*PI/N,b);
		for(int i=0;i<N;i++) x[i]*=b[i];
		x=fft(N,-2*PI/N,x);
		vector <int> ret;
		for(int i=0;i<x.size();i++) ret.push_back((int) (x[i].real()/N+0.5));
		return ret;
	}
};
FFT solve;
char str[SIZE];
bool ans[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",&str);
		vector <int> A,B;
		A.resize(n,0);
		B.resize(n,0);
		for(int i=0;i<n;i++)
		{
			if(str[i]=='V')
			{
				A[i]++;
			}
			else if(str[i]=='K')
			{
				B[n-i-1]++;
			}
		}
		for(int i=1;i<=n;i++) ans[i]=false;
		vector <int> gt=solve.getFFT(A,B);
		for(int i=0;i<gt.size();i++)
		{
			if(gt[i]>0)
			{
				int v=abs(i+1-n);
				if(v<=n) ans[v]=true;
			}
		}
		vector <int> ret;
		for(int i=1;i<=n;i++)
		{
			bool up=false;
			for(int j=i;j<=n;j+=i) up|=ans[j];
			if(!up) ret.push_back(i);
		}
		printf("%d\n",ret.size());
		for(int i=0;i<ret.size();i++)
		{
			if(i!=0) printf(" ");
			printf("%d",ret[i]);
		}puts("");
	}
	return 0;
}