#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int B=200000;
string s;
int to;
ll mod;
ll mul(ll x,ll y)
{
	ll ret=0;
	for(;x;x>>=1)
	{
		if(x&1)ret^=y;
		y<<=1;
		if(y>>(to-1)&1)y^=mod;
	}
	return ret;
}
int main()
{
	cin>>s;
	s.erase(s.find_last_not_of('0')+1);
	int delta=s.find_first_not_of('0');
	s.erase(0,delta);delta++;
	for(int i=0;i<s.size();i++)if(s[i]=='1')mod|=1ll<<i;
	to=s.size();
	if(__builtin_popcountll(mod)==0){puts("-1");return 0;}
	if(__builtin_popcountll(mod)==1){printf("%d %d\n",delta,delta+1);return 0;}
	if(__builtin_popcountll(mod)==2){printf("%d %d\n",delta,delta+to-1);return 0;}
	unordered_map<ll,int>exi;
	ll bas=1,pos=-1;
	for(int i=0;i<B;i++)
	{
		exi[bas]=i;
		bas=mul(bas,2);
	}
	ll now=1;
	for(int i=1;;i++)
	{
		now=mul(now,bas);
		if(exi.count(now)){pos=(ll)i*B-exi[now];break;}
	}
	printf("%d %lld\n",delta,delta+pos);
	return 0;
}