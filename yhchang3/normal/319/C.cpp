#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct Line{
	ll k,b;
	Line(ll k=0,ll b=0):k(k),b(b){}
	ll eval(ll x){
		return k*x+b;
	}
};

bool bad(Line L1,Line L2,Line L3){
	return (long double)(L2.b-L1.b)*(L1.k-L3.k)>=(long double)(L1.k-L2.k)*(L3.b-L1.b);
}

ll a[100010],b[100010];
ll dp[100010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	deque<Line> v;
	dp[1]=0;
	v.emplace_back(Line(b[1],dp[1]));
	for(int i=2;i<=n;i++){
		while(v.size()>=2&&v[0].eval(a[i])>=v[1].eval(a[i]))
			v.pop_front();
		dp[i]=v[0].eval(a[i]);
		Line L = Line(b[i],dp[i]);
		while(v.size()>=2&&bad(v[v.size()-2],v.back(),L))
			v.pop_back();
		v.emplace_back(L);
	}
	cout<<dp[n]<<endl;
}