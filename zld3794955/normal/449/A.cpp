#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int V=100000;
long long n,m,k,ans=0;
pair<long long,long long>a[V],b[V];
int main()
{	
	cin>>n>>m>>k;
	k+=2;
	if(n+m<k)
	{
		puts("-1");
		return 0;
	}
	int tot1=0,tot2=0;
	long long end=0;
	for(long long i=1;i<=n;i=end+1)
	{
		end=n/(n/i);
		a[++tot1]=make_pair(i,n/i);
	}
	a[++tot1]=make_pair(n+1,0);
	//for(int i=1;i<=tot1;++i)
	//	cout<<a[i].first<<' '<<a[i].second<<endl;
	for(long long i=1;i<=m;i=end+1)
	{
		end=m/(m/i);
		b[++tot2]=make_pair(i,m/i);
	}
	b[++tot2]=make_pair(m+1,0);
	//for(int i=1;i<=tot2;++i)
	//	cout<<b[i].first<<' '<<b[i].second<<endl;
	//cout<<"----------------------"<<endl;
	int pos=tot2;
	for(int i=1;i<tot1;++i)
	{
		while(pos && b[pos].first>k-a[i+1].first+1)
			--pos;
		//cout<<a[i].first<<' '<<b[pos].first<<endl;
		ans=max(a[i].second*b[pos].second,ans);
	}
	pos=tot1;
	for(int i=1;i<tot2;++i)
	{
		while(pos && a[pos].first>k-b[i+1].first+1)
			--pos;
		//cout<<a[i].first<<' '<<b[pos].first<<endl;
		ans=max(b[i].second*a[pos].second,ans);
	}
	cout<<ans<<endl;
	return 0;
}