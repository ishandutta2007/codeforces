#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 2010
#define M 
using namespace std;

ll n,k,mx[N][N],mn=N*N;
bool in[N][N];
P t2;
string ans;
char mm[N][N];
vector<P>now,tmp;

int main()
{
	ll i,j,p,q,t;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%s",mm[i]+1);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mx[i][j]=max(mx[i-1][j],mx[i][j-1])+(mm[i][j]=='a');
			mn=min(mn,i+j-1-mx[i][j]);
		}
	}
	if(n*2-1-mx[n][n]<=k)
	{
		for(i=1;i<=n*2-1;i++) printf("a");
		return 0;
	}
	t=0;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(i+j-1-mx[i][j]<=k) t=max(t,i+j);
	for(i=1;i<t;i++) ans+="a";
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(i+j-1-mx[i][j]<=k && i+j==t)
	{
		now.push_back(mp(i,j));
	}
	if(!k) ans=mm[1][1],now.push_back(mp(1,1));
	for(;now[0]!=mp(n,n);)
	{
		char z='{';
		for(i=0;i<now.size();i++)
		{
			t2=now[i];
			p=t2.fi,q=t2.se;
			if(p+1<=n) z=min(z,mm[p+1][q]);//,cout<<p+1<<" "<<q<<" "<<mm[p+1][q]<<endl;
			if(q+1<=n) z=min(z,mm[p][q+1]);//,cout<<p<<" "<<q+1<<endl;;
		}
		ans+=z;
		for(i=0;i<now.size();i++)
		{
			t2=now[i];
			p=t2.fi,q=t2.se;
			if(p+1<=n&&mm[p+1][q]==z&&!in[p+1][q]) tmp.push_back(mp(p+1,q)),in[p+1][q]=1;
			if(q+1<=n&&mm[p][q+1]==z&&!in[p][q+1]) tmp.push_back(mp(p,q+1)),in[p][q+1]=1; 
		}
		now.clear();
		for(i=0;i<tmp.size();i++) now.push_back(tmp[i]);
		tmp.clear();
	}
//	if(n==2000) while(1);
	cout<<ans;
}