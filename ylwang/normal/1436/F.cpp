// copy from others

#include<bits/stdc++.h>
using namespace std;

// #define int long long

const int p=998244353;
const int i2=499122177;

int S[100010];
int f[100010];

inline
int Mod(long long a)
{
	return a>=p?a-p:(a<0?a+p:a);
}
inline
int quickPow(int a,long long k)
{
	k%=p-1;
	int res=1,w=a;
	while(k)
	{
		if(k&1)
		{
			res=1ll*res*w%p;
		}
		w=1ll*w*w%p;
		k>>=1;
	}
	return res;
}
inline
int calcSum(int a1,int d,int n)
{
	return (1ll*Mod(1ll*2*a1%p+1ll*(n-1)*d%p)*n%p)*i2%p;
}
//
signed main()
{
	int n,mxA=0;
	cin>>n;
	for(int i=1,a,c;i<=n;i++)
	{
		cin>>a>>c;
		mxA=max(mxA,a);
		S[a]+=c;
	}

	for(int i=mxA;i>=1;i--)
	{
		long long szA=0;
		int sum=0,smE=0,smN=0;
		for(int j=i;j<=mxA;j+=i)
		{
			if(S[j]!=0)
			{
				szA=szA+S[j];
				smE=Mod(smE+(1ll*j*j%p)*(S[j]%p)%p);
				smN=Mod(smN+(1ll*2*calcSum(sum,j,S[j])%p)*j%p);
				sum=Mod(sum+1ll*(S[j]%p)*j%p);
			}
		}
		if(szA>=2)
		{
			f[i]=Mod(f[i]+(1ll*smE*quickPow(2,szA-2)%p)*((szA-1)%p)%p);
			f[i]=Mod(f[i]+1ll*smN*quickPow(2,szA-2)%p);
		}
		if(szA>=3)
		{
			f[i]=Mod(f[i]+(1ll*smN*quickPow(2,szA-3)%p)*((szA-2)%p)%p);
		}

		for(int j=i*2;j<=mxA;j+=i)
		{
			f[i]=Mod(f[i]-f[j]);
		}
	}
	cout<<f[1]<<endl;
}