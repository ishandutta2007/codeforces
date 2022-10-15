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
const int maxn=4e3+5,mod=1e9+7;
void add(int &x,int y){x=(x+y>=mod)?x+y-mod:x+y;}
int qmod(int x){return x>=mod?x-mod:x;}
int p,a;
struct bigint
{
	vector<int>v;
	void init(){string s;cin>>s;for(int i=s.size()-1;i>=0;i--)v.push_back(s[i]-'0');}
	int operator /(int x)
	{
		ll ret=0;
		for(int i=v.size()-1;i>=0;i--){ret=ret*10+v[i];v[i]=ret/x;ret%=x;}
		while(!v.empty()&&!v.back())v.pop_back();
		return ret;
	}
}n;
int val[maxn],top;
int S(int n){if(n<0)return 0;n++;return ((ll)n*(n+1)/2)%mod;}
int calc(int lim){return qmod((ll)S(lim)-2ll*S(lim-p)%mod+mod);}
int f[maxn][maxn][2][2],ans;
int main()
{
	p=read();a=read();
	n.init();while(!n.v.empty())val[top++]=n/p;
	f[0][0][0][1]=calc(val[0]);
	f[0][0][0][0]=qmod(calc(p-1)-calc(val[0])+mod);
	f[0][1][1][1]=qmod(calc(p+val[0])-calc(p-1)+mod);
	f[0][1][1][0]=qmod(calc(2*p-2)-calc(p+val[0])+mod);
	for(int i=0;i<top;i++)
		for(int j=0;j<=i+1;j++)
			for(int k=0;k<=1;k++)
				for(int l=0;l<=1;l++)
				{
					if(!f[i][j][k][l])continue;
					add(f[i+1][j][0][1],(ll)f[i][j][k][l]*calc(val[i+1]-k-1)%mod);
					add(f[i+1][j][0][l],(ll)f[i][j][k][l]*(calc(val[i+1]-k)-calc(val[i+1]-k-1)+mod)%mod);
					add(f[i+1][j][0][0],(ll)f[i][j][k][l]*(calc(p-1-k)-calc(val[i+1]-k)+mod)%mod);
					add(f[i+1][j+1][1][1],(ll)f[i][j][k][l]*(calc(p+val[i+1]-1-k)-calc(p-1-k)+mod)%mod);
					add(f[i+1][j+1][1][l],(ll)f[i][j][k][l]*(calc(p+val[i+1]-k)-calc(p+val[i+1]-1-k)+mod)%mod);
					add(f[i+1][j+1][1][0],(ll)f[i][j][k][l]*(calc(2*p-2)-calc(p+val[i+1]-k)+mod)%mod);
				
				}
	for(int i=a;i<=top;i++)add(ans,f[top][i][0][1]);
	printf("%d\n",ans);
	return 0;
}