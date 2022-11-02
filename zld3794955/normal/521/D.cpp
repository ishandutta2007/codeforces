#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int k,n,m,num[N]={},t[N]={},u[N]={},v[N]={};
long long a[N]={},b[N]={},w[N]={};
vector<pair<int,int>> add[N],mul;
void init()
{
	cin>>k>>n>>m;
	for(int i=1;i<=k;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		cin>>t[i]>>u[i]>>v[i];
		if(t[i]==1 && v[i]>b[u[i]])
		{
			b[u[i]]=v[i];
			num[u[i]]=i;
		}
		if(t[i]==2)
			add[u[i]].push_back({v[i],i});
		if(t[i]==3)
			mul.push_back({v[i],i});
	}
	for(int i=1;i<=k;++i)
		if(b[i]>a[i])
			add[i].push_back({b[i]-a[i],-num[i]});
	for(int i=1;i<=k;++i)
		sort(add[i].rbegin(),add[i].rend());
	sort(mul.rbegin(),mul.rend());
	copy(a+1,a+k+1,w+1);
}
void work()
{
	double sum=0,maxv=0;
	vector<int> opera;
	int ansp1=0,ansp2=0;
	set<pair<double,pair<int,int>>> s;
	int d=min((int)mul.size(),m);
	for(int i=0;i<d;++i)
		sum+=log(mul[i].first);
	for(int i=1;i<=k;++i)
		if(add[i].size())
			s.insert({log(w[i]+add[i][0].first)-log(w[i]),{i,0}});
	maxv=sum;
	ansp1=0,ansp2=d;
	for(int i=0;i<m && !s.empty();++i)
	{
		while(i+d>=m)
			sum-=log(mul[--d].first);
		auto p=*s.rbegin();
		s.erase(s.find(p));
		sum+=p.first;
		int x=p.second.first,y=p.second.second;
		opera.push_back(add[x][y].second);
		w[x]+=add[x][y].first;
		if((++y)!=(int)add[x].size())
			s.insert({log(w[x]+add[x][y].first)-log(w[x]),{x,y}});
		if(sum>maxv)
			maxv=sum,ansp1=opera.size(),ansp2=d;
	}
	sort(opera.begin(),opera.begin()+ansp1);
	cout<<ansp1+ansp2<<endl;
	for(int i=0;i<ansp1;++i)
		cout<<abs(opera[i])<<' ';
	for(int i=0;i<ansp2;++i)
		cout<<mul[i].second<<' ';
	cout<<endl;
}
int main()
{	
	init();
	work(); 
	return 0;
}