#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll read()
{
	ll ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e3+5;
mt19937 rnd(0);
int Rand(int l,int r){return uniform_int_distribution<>(l,r)(rnd);}
ll ansl[maxn],ansr[maxn];
int n;ll L;
ll query(int id,ll pos)
{
	printf("? %d %lld\n",id,pos);
	fflush(stdout);return read();
}
ll getpos(int id,ll val,ll l,ll r)
{
	ll ret=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(query(id,mid)>=val)ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
ll getmid(vector<int>f,ll l,ll r,ll L,ll R,ll val,int to)
{
	int id=f[Rand(0,f.size()-1)];
	ll pos=getpos(id,val,l,r);
	vector<int>lp,rp,mp;
	for(int &i:f)
	{
		ll now=query(i,pos);
		if(now<val)rp.push_back(i);
		if(now>val)lp.push_back(i);
		if(now==val)mp.push_back(i);
	}
	while(lp.size()<to&&!mp.empty())lp.push_back(mp.back()),mp.pop_back();
	while(!mp.empty())rp.push_back(mp.back()),mp.pop_back();
	if(lp.size()==to)return pos;
	if(lp.size()>to)return getmid(lp,l,r,L,R,val,to);
	return getmid(rp,l,r,L,R,val,to-lp.size());
}
void solve(vector<int>f,ll l,ll r,ll L,ll R)
{
	if(!f.size())return;
	if(f.size()==1){ansl[f[0]]=l;ansr[f[0]]=r;return;}
	ll mid=L+(::L/::n)*(f.size()/2);
	ll now=getmid(f,l,r,L,R,mid,f.size()/2);
	vector<int>lp,mp,rp;
	for(int &i:f)
	{
		ll val=query(i,now);
		if(val>mid)lp.push_back(i);
		else if(val==mid)mp.push_back(i);
		else rp.push_back(i);
	}
	vector<int>p;
	p.insert(p.end(),lp.begin(),lp.end());
	p.insert(p.end(),mp.begin(),mp.end());
	p.insert(p.end(),rp.begin(),rp.end());
	lp.clear();rp.clear();
	lp.insert(lp.end(),p.begin(),p.begin()+p.size()/2);
	rp.insert(rp.end(),p.begin()+p.size()/2,p.end());	
	solve(lp,l,now,L,mid);
	solve(rp,now,r,mid,R);
}
int main()
{
	n=read();L=read();
	vector<int>tmp(n);
	iota(tmp.begin(),tmp.end(),1);
	solve(tmp,0,1e18,0,L);
	puts("!");
	for(int i=1;i<=n;i++)printf("%lld %lld\n",ansl[i],ansr[i]);
	fflush(stdout);
	return 0;
}