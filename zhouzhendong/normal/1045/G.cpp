#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#define ll long long
#define lb(x) (x&(-x))
#define N 100100
using namespace std;

ll n,m,iq[N],ii,tt,ci,ans;
struct Rob
{
	ll IQ,pos,r;
	bool operator < (const Rob &u) const
	{
		return r<u.r;
	}
}rob[N];
struct Sz
{
	ll cnt;
	vector<ll>num,sz;
	map<ll,ll>zh;
	set<ll>se;
	set<ll>::iterator it;
	void add(ll u,ll v){for(;u<=cnt;u+=lb(u)) sz[u]+=v;}
	ll ask(ll u){ll res=0;for(;u;u-=lb(u)) res+=sz[u];return res;}
	void lsh()
	{
		ll i,j;
		sort(num.begin(),num.end());
		for(i=0;i<num.size();i++)
		{
			if(!i||num[i]!=num[i-1])
			{
				cnt++;
				zh[num[i]]=cnt;
				se.insert(num[i]);
			}
		}
		sz.resize(cnt+1);
	}
	ll as(ll u)
	{
//		exit(0);
		it=se.upper_bound(u);
		if(it==se.begin()) return 0;
		it--;
//		cout<<(*it)<<endl;
		return ask(zh[*it]);
	}
	void in(ll w)
	{
		ll u=rob[w].pos-rob[w].r,v=rob[w].pos+rob[w].r+1;
		u=zh[u],v=zh[v];
//		cout<<u<<" "<<v<<" "<<cnt<<endl;
//		exit(0);
		add(u,1),add(v,-1);
//		exit(0);
	}
}sz[N];
map<ll,ll>mm;

int main()
{
	ll i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&rob[i].pos,&rob[i].r,&rob[i].IQ);
		iq[++ii]=rob[i].IQ;
	}
	sort(rob+1,rob+n+1);
	sort(iq+1,iq+ii+1);
	for(i=1;i<=ii;i++)
	{
		if(i==1||iq[i]!=iq[i-1])
		{
			iq[++ci]=iq[i];
			mm[iq[i]]=ci;
		}
	}
	for(i=1;i<=n;i++) rob[i].IQ=mm[rob[i].IQ];
	
	for(i=1;i<=n;i++)
	{
		sz[rob[i].IQ].num.push_back(rob[i].pos-rob[i].r);
		sz[rob[i].IQ].num.push_back(rob[i].pos+rob[i].r+1);
	}
	for(i=1;i<=ci;i++) sz[i].lsh();
//	return 0;
	for(i=1;i<=n;i++)
	{
		for(j=iq[rob[i].IQ]-m;j<=iq[rob[i].IQ]+m;j++)
		{
			if(mm.count(j))
			{
				ans+=sz[mm[j]].as(rob[i].pos);
			}
		}
//		cout<<i<<endl;
//		return 0;
		sz[rob[i].IQ].in(i);
//		cout<<" "<<i<<endl;
//		return 0;
	}
	cout<<ans;
}