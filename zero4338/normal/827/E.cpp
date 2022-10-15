#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=5e5+5,mod=998244353;
string s;
int exi[maxn];
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int R[1<<21],W[1<<21];
struct poly
{
	vector<int>v;
	int&operator[](const int &i){return v[i];}
	int len(){return v.size();}
	void set(int l){v.resize(l);}
	void ntt(int L,int typ)
	{
		int n=1<<L;
		for(int i=0;i<n;i++)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		W[0]=1;W[1]=qpow(3,(mod-1)/n);if(typ==-1)W[1]=qpow(W[1],mod-2);
		for(int i=2;i<n;i++)W[i]=(ll)W[i-1]*W[1]%mod;
		set(n);for(int i=0;i<n;i++)if(R[i]>i)swap(v[R[i]],v[i]);
		for(int t=n>>1,d=1;d<n;d<<=1,t>>=1)
			for(int i=0;i<n;i+=(d<<1))
				for(int j=0;j<d;j++)
				{
					int tmp=(ll)W[t*j]*v[i+j+d]%mod;
					v[i+j+d]=(v[i+j]-tmp+mod)%mod;
					v[i+j]=(v[i+j]+tmp)%mod;
				}
		if(typ==-1){int inv=qpow(n,mod-2);for(int i=0;i<n;i++)v[i]=(ll)v[i]*inv%mod;}
	}
	poly operator *(poly x)
	{
		poly tmp=*this,ret;
		int L=ceil(log2(tmp.len()+x.len())),n=1<<L;
		tmp.ntt(L,1);x.ntt(L,1);
		ret.set(n);for(int i=0;i<n;i++)ret[i]=(ll)tmp[i]*x[i]%mod;ret.ntt(L,-1);
		return ret;
	}
};
int main()
{
	int T=read();
	while(T--)
	{
		read();
		cin>>s;
		poly f,g;
		f.set(s.size());g.set(s.size());
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='V')f[i]=1;
			if(s[i]=='K')g[s.size()-1-i]=1;
		}
		f=f*g;
		for(int i=1;i<=s.size();i++)exi[i]=false;
		for(int i=0;i<f.len();i++)if(f[i])exi[abs(i-(int)s.size()+1)]=true;
		vector<int>ans;
		for(int i=1;i<s.size();i++)
		{
			bool flag=true;
			for(int j=i;j<=s.size();j+=i)if(exi[j]){flag=false;break;}
			if(flag)ans.push_back(i);
		}
		ans.push_back(s.size());
		printf("%lu\n",ans.size());
		for(int &i:ans)printf("%d ",i);putchar('\n');
	}
	return 0;
}