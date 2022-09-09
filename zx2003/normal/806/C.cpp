#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int n,i,j,cnt,l,r,m,xb;
ll a[N],lst1,b[N],c[N];
map<ll,int>mp;
map<ll,int>::iterator it;
bool check(int m){
	int xbb=cnt,i;
	static ll d[N];
	memcpy(d+1,c+1,cnt<<3);
	memset(b+1,0,m<<3);
	for(it=mp.begin();it!=mp.end();++it){
		for(i=1;i<=it->second && i<=m;++i){
			if(b[i]!=it->first>>1)break;
			b[i]=it->first;
		}
		for(;i<=it->second;++i)d[++xbb]=it->first;
	}
	sort(d+1,d+xbb+1);
	if(xbb>m)return 0;
	for(i=1;i<=xbb;++i)if(d[i]>b[xbb-i+1]<<1)return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i];
		if(!(a[i]&(a[i]-1)))++mp[a[i]];
			else ++cnt,c[cnt]=a[i];
	}
	if(mp.begin()->first!=1)return cout<<"-1",0;
	it=++mp.begin();
	lst1=1;
	for(;it!=mp.end();++it){
		if(it->first!=lst1<<1)return cout<<"-1",0;
		lst1=it->first;
	}
	l=cnt,r=mp.begin()->second;
	if(!check(r))return cout<<"-1",0;
	if(l<1)l=1;
	for(;l<r;){
		m=(l+r)>>1;
		if(check(m))r=m;
			else l=m+1;
	}
	for(i=l;i<=mp.begin()->second;++i)cout<<i<<' ';
	return 0;
}