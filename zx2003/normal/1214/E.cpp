#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,i,j,d[N];
pair<int,int>a[N];
vector<int>v,v2;
bool b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",d+i),a[i]=make_pair(d[i],i);
	sort(a+1,a+n+1);
	v.push_back(a[n].second*2);v2.push_back(a[n].second*2-1);
	for(i=1;i<a[n].first;++i){
		v.push_back(a[n-i].second*2);
		if(a[n-i].first+i>a[n].first+v2.size()-1)v2.push_back(a[n-i].second*2-1);else b[i]=1;
	}
	for(int x:v2)v.push_back(x);
	for(i=0;i+1<v.size();++i)printf("%d %d\n",v[i],v[i+1]);
	for(i=1;i<a[n].first;++i)if(b[i])printf("%d %d\n",a[n-i].second*2-1,v[i+a[n-i].first-1]);
	for(;i<n;++i){
		printf("%d %d\n",v[0],a[n-i].second*2);
		if(a[n-i].first==1)printf("%d %d\n",a[n-i].second*2,a[n-i].second*2-1);
			else printf("%d %d\n",a[n-i].second*2-1,v[a[n-i].first-2]);
	}
	return 0;
}