#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 500005
#define mod 998244353
#define G 3
#define gi 332748118
#define pb push_back
//#define int long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,fac[N],ifac[N],inv[N],rev[N];
vector<int>f,g;
int mul(int x,int y){return 1ll*x*y%mod;}
int get_limit(int x)
{
	int limit=1;while(limit<=x)limit<<=1;
    for(int i=0;i<limit;i++)rev[i]=(rev[i>>1]>>1|(i&1?limit>>1:0));
	return limit;
}
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=mul(res,a),res%=mod;
		a=mul(a,a);a%=mod;
		b>>=1;
	}
	return res;
}
void NTT(vector<int>&a,int limit,int type)
{
	for(int i=0;i<limit;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int mid=1;mid<limit;mid<<=1)
	{
		int Wn=ksm(type==1?G:gi,(mod-1)/(mid<<1));
		//cout<<"!!!!!!!!"<<Wn<<endl;
		for(int j=0;j<limit;j+=(mid<<1))
		{
			int w=1;
			for(int k=0;k<mid;k++,w=mul(w,Wn))
			{
				int x=a[j+k],y=mul(w,a[j+k+mid]);
				a[j+k]=(x+y)%mod;a[j+k+mid]=(x-y+mod)%mod;
			}
		}
	}
	if(type==-1)
	{
		int INV=ksm(limit,mod-2);
		for(int i=0;i<limit;i++)a[i]=mul(a[i],INV);
	}
	//return a;
}
vector<int> operator*(vector<int>a,vector<int>b)
{
	int len=a.size()+b.size()-1;
	int limit=get_limit(len);
	//cout<<"@@@@@@@@@@@@@@"<<len<<endl;
	a.resize(limit);b.resize(limit);
	for(int i=0;i<limit;i++)rev[i]=(rev[i>>1]>>1|(i&1?limit>>1:0));
	NTT(a,limit,1);NTT(b,limit,1);	
	for(int i=0;i<limit;i++)a[i]=mul(a[i],b[i])%mod;
	NTT(a,limit,-1);a.resize(len);
	return a;
}
signed main()
{
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
	for(int i=2;i<=500000;i++)
	{
		//inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		inv[i]=mul((mod-mod/i),inv[mod%i]);
		//ifac[i]=ifac[i-1]*inv[i]%mod;
		ifac[i]=mul(ifac[i-1],inv[i]);
		//fac[i]=fac[i-1]*i%mod;
		fac[i]=mul(fac[i-1],i);
	}
	f.pb(0);f.pb(1);
	n=read();
	while(n--)
	{
		int a=read(),b=read();
		int MAXJ=a-b+f.size()-1,MAXK=f.size()-1;
//		cout<<MAXJ<<" "<<MAXK<<endl;
		g.clear();int ff=1e9;
		for(int i=1-MAXK;i<=MAXJ-1;i++)//j-k
		{
			if(a-i>=0&&b+i>=0)
			{
				if(ff==1e9)ff=i;
				g.pb(mul(ifac[a-i],ifac[b+i]));
			}
		}
//		puts("---------------------");
//		for(int i=0;i<f.size();i++)printf("%d ",f[i]);
//		puts("");
//		for(int i=0;i<f.size();i++)printf("%d ",g[i]);
//		puts("");	
//		puts("---------------------");
		f=f*g;
		for(int i=0;i<f.size();i++)f[i]=mul(f[i],fac[a+b])%mod;
		vector<int>tmp;tmp.clear();
		for(int i=0;i<f.size();i++)
		{
            if(ff>=0&&ff<=MAXJ)tmp.pb(f[i]);
            ff++;
      }
      f=tmp;f[0]=0;
	}
	int ans=0;
	for(int i=1;i<f.size();i++)ans+=f[i],ans%=mod;
	cout<<ans<<endl;
	return 0;
}