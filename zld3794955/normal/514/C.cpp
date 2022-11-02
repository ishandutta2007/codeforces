#include<bits/stdc++.h>
using namespace std;
const long long Base=17,mod=1000000000000007ll;
struct data
{
	long long p,s,h;
};
bool data_cmp(const data &x,const data &y)
{
	return x.p<y.p || (x.p==y.p && (x.s<y.s || (x.s==y.s && x.h<y.h)));
}
int n,m;
string s;
vector<long long> v;
vector<data> table;
bool find(const data &d)
{
	//cout<<d.p<<' '<<d.s<<' '<<d.h<<endl;
	auto it1=upper_bound(table.begin(),table.end(),d,data_cmp);
	auto it2=lower_bound(table.begin(),table.end(),d,data_cmp)-1;
	return (it1->p==d.p && it1->s==d.s && it1->h!=d.h)
		|| (it2->p==d.p && it2->s==d.s && it2->h!=d.h);
}
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		v.clear();
		int l=s.size();
		v.resize(l+1,0ll);
		v[l]=l;
		for(int j=l-1;j>=0;--j)
			v[j]=(v[j+1]*Base+s[j])%mod;
		long long tmp=l;
		for(int j=0;j<l;++j)
		{
			table.push_back({tmp,v[j+1],v[0]});
			tmp=(tmp*Base+s[j]-'a')%mod;
		}
	}
	table.push_back({0ll,0ll,0ll});
	sort(table.begin(),table.end(),data_cmp);
	//for(auto now:table)
	//	cout<<now.p<<' '<<now.s<<' '<<now.h<<endl;
	for(int i=1;i<=m;++i)
	{
		cin>>s;
		v.clear();
		int l=s.size();
		v.resize(l+1,0ll);
		v[l]=l;
		for(int j=l-1;j>=0;--j)
			v[j]=(v[j+1]*Base+s[j])%mod;
		long long tmp=l;
		bool flag=false;
		for(int j=0;j<l;++j)
		{
			if(find({tmp,v[j+1],v[0]}))
			{
				puts("YES");
				flag=true;
				break;
			}
			tmp=(tmp*Base+s[j]-'a')%mod;
		}
		if(!flag)
			puts("NO");
	}
	return 0;
}