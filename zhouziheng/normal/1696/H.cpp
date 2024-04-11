#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const long long MOD=1e9+7;
vector<long long> P,N;
long long pc[1000][1000],nc[1000][1000],spc[1000][1000],snc[1000][1000],pw2[1000],totn[1000],totp[1000];

int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}
long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}return ans;
}
struct nd
{
	long long val;int type,l,r;
	nd(long long _val=0,int _type=0,int _l=0,int _r=0):val(_val),type(_type),l(_l),r(_r){}
};
bool operator<(nd A,nd B){return A.val<B.val;}
vector<nd> V;

int main()
{
	int n=0,k=0;scanf("%d%d",&n,&k);
	pw2[0]=1;for(int i=1;i<=n;i++)pw2[i]=add(pw2[i-1],pw2[i-1]);
	for(int i=1;i<=n;i++)
	{
		int a=0;scanf("%d",&a);
		if(a>=0)P.push_back(a);else N.push_back(-a);
	}
	sort(P.begin(),P.end());sort(N.begin(),N.end());
	
	pc[P.size()][0]=spc[P.size()][0]=1;
	for(int i=P.size()-1;i>=0;i--)
	{
		for(int j=1;j<=n;j++){pc[i][j]=spc[i+1][j-1]*P[i]%MOD;}
		for(int j=0;j<=n;j++)
		{
			spc[i][j]=add(spc[i+1][j],pc[i][j]);
		}
	}
	for(int i=P.size();i>=0;i--)for(int j=0;j<=n;j++)totp[j]=add(totp[j],pc[i][j]*pw2[i]%MOD);
	
	nc[N.size()][0]=snc[N.size()][0]=1;
	for(int i=N.size()-1;i>=0;i--)
	{
		for(int j=1;j<=n;j++){nc[i][j]=snc[i+1][j-1]*N[i]%MOD;}
		for(int j=0;j<=n;j++)
		{
			snc[i][j]=add(snc[i+1][j],nc[i][j]);
		}
	}
	for(int i=N.size();i>=0;i--)for(int j=0;j<=n;j++)totn[j]=add(totn[j],nc[i][j]*pw2[i]%MOD);
	
	//for(int i=0;i<=n;i++)printf("%lld ",totp[i]);puts("");
	//for(int i=0;i<=n;i++)printf("%lld ",totn[i]);puts("");
	
	long long ans=0;
	for(int i=0;i<=k;i+=2)ans=add(ans,totn[i]*totp[k-i]%MOD);
	//printf("%lld\n",ans);
	
	memset(totn,0,sizeof(totn));memset(totp,0,sizeof(totp));
	for(int i=0;i<P.size();i++)for(int j=i+1;j<P.size();j++)
	{
		V.push_back(nd(P[i]*P[j],0,i,j));
	}
	for(int i=0;i<N.size();i++)for(int j=i+1;j<N.size();j++)
	{
		V.push_back(nd(N[i]*N[j],1,i,j));
	}
	sort(V.begin(),V.end());
	for(int i=0;i<V.size();i++)
	{
		if(V[i].type==0)
		{
			for(int j=0;j<=k&&j<=N.size();j+=2)
			{
			if(k-j>P.size())continue;	
			ans=sub(ans,totn[j]*pw2[V[i].l]%MOD*spc[V[i].r+1][k-j]%MOD);
			}
			for(int j=(k&1);j<=k;j+=2)totp[j+2]=add(totp[j+2],(V[i].val%MOD)*spc[V[i].r+1][j]%MOD*pw2[V[i].l]%MOD);
		}
		else
		{
			for(int j=0;j<=k&&j<=N.size();j+=2)
			{
			if(k-j>P.size())continue;	
			ans=sub(ans,totp[k-j]*pw2[V[i].l]%MOD*snc[V[i].r+1][j]%MOD);
			}
			for(int j=0;j<=k;j+=2)totn[j+2]=add(totn[j+2],(V[i].val%MOD)*snc[V[i].r+1][j]%MOD*pw2[V[i].l]%MOD);
		}
	}
	//printf("%lld\n",ans);
	for(int i=1;i<=k;i+=2)ans=sub(ans,snc[0][i]*spc[0][k-i]%MOD);
	if(k&1)
	{
		memset(snc,0,sizeof(snc)),memset(nc,0,sizeof(nc));
		snc[0][0]=nc[0][0]=1;
		for(int i=1;i<=N.size();i++)
		{
			for(int j=0;j<=n;j++)nc[i][j+1]=snc[i-1][j]*N[i-1]%MOD;
			for(int j=0;j<=n;j++)snc[i][j]=add(snc[i-1][j],nc[i][j]);
		}
		for(int i=1;i<=N.size();i++)ans=sub(ans,nc[i][k]*sub(pw2[N.size()-i],1)%MOD);
	}
	
	printf("%lld",ans);
	
}