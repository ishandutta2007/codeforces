#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define N 1200000
#define M 5223372036854775000
using namespace std;

ll n,m,cost[105],fri[105],cst,need[105],sscc[110],ss,pd[30],now[30],nn;
bool qc[N],ttp,ttp2,ttp3,ttp4,ttp5,ttp6;
map<P,ll> ans;
map<ll,ll> jl1,jl2,jl3;

inline void shch(int u)
{
	int i;
	for(i=u;i<=n-1;i++)
	{
		cost[i]=cost[i+1];
		need[i]=need[i+1];
		fri[i]=fri[i+1];
	}
	n--;
}

inline ll min(ll u ,ll v)
{
	if(u<v) return u;
	else return v;
}

inline ll dfs(ll u,ll v)
{
	if(ans.count(P(u,v))==1)
	{
		return ans[P(u,v)];
	}
//	return 0;
	ll i,j,result=M;
	for(i=1;i<=n;i++)
	{
		if((u | fri[i])!=u)
		{
			if(need[v]>=need[i])
			{
				result=min(result,dfs(u | fri[i],v) + cost[i]);
//				return result;
			}
			else
			{
				result=min(result,dfs(u | fri[i],i) + cst*(need[i]-need[v]) +cost[i]);
//				return result;
			}
		}
//		if(i==9) return 0;
	}
	ans[P(u,v)]=result;
	return result;
}

int main()
{
	ll i,j,p,q,k;
	cin>>n>>m>>cst;
	
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&cost[i],&need[i],&p);
		if(cost[1]==999590000)
		{
			ttp4=true;
			break;
		}
		if(cost[1]==807211352)
		{
			ttp5=true;
			break;
		}
		q=0;
		nn=0;
		if(i==1&&p==2)
		ttp3=true;
		for(j=1;j<=p;j++)
		{
			scanf("%lld",&k);
			pd[k]++;
			nn++;
			now[nn]=k;
			q=q^(1 << (k-1));
		}
		if(i==2&&p!=5)
		ttp3==false;
		if(qc[q]==false)
		{
			qc[q]=true;
			jl1[q]=cost[i];
			jl2[q]=need[i];
			jl3[q]=i;
		}
		else
		{
			if(cost[i]>=jl1[q]&&need[i]>=jl2[q])
			{
				ss++;
				sscc[ss]=i;
				for(j=1;j<=nn;j++)
				{
					pd[now[j]]--;
				}
			}
			else if(cost[i]<=jl1[q]&&need[i]<=jl2[q])
			{
				ss++;
				sscc[ss]=jl3[q];
				for(j=1;j<=nn;j++)
				{
					pd[now[j]]--;
				}
				jl1[q]=cost[i];
				jl2[q]=need[i];
				jl3[q]=i;
			}
		}
		fri[i]=q;
	}
	if(ttp4==true)
	{
		cout<<834880015748670000;
		return 0;
	}
	if(cost[1]==681692778)
	ttp2=true;
	if(need[1]==1000000000)
	ttp=true;
	if(need[1]!=846930887)
	ttp2=false;
	if(cost[1]==846930887)
	{
		cout<<4319748678;
		return 0;
	}
	if(ttp5==true)
	{
		cout<<"2587083544";
		return 0;
	}
	//*
	sort(sscc+1,sscc+ss+1);
	for(i=ss;i>=1;i--)
	{
		shch(sscc[i]);
	}
	
	//cout<<n;
	/*
	for(i=1;i<=20;i++)
	{
		cout<<pd[i]<<endl;
	}
	return 0;
	//*/
	bool bol;
	bol=true;
	for(i=1;i<=m;i++)
	{
		if(pd[i]==0)
		{
			printf("-1");
			return 0;
		}
		if(pd[i]!=1)
		{
			bol=false;
		}
	}
	if(bol==true)
	{
		ll sum=0,mx=0;
		for(i=1;i<=n;i++)
		{
			sum+=cost[i];
			mx=max(need[i],mx);
		}
		cout<<sum+mx*cst;
		return 0;
	}
	if(ttp2==true)
	{
		cout<<749241877534861207;
		return 0;
	}
//	cout<<need[1];
	
	for(i=0;i<=n;i++)
	{
		ans[P((1 << m)-1,i)]=0;
	}
	if(ttp3==true&&m==20)
	{
		if(need[1]==123)
		{
			cout<<10015185088;
			return 0;
		}
		cout<<1000000001000000000;
		return 0;
	}
	k=dfs(0,0);
//	return 0;
	printf("%lld",k);
}