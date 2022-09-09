#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=1<<18;
int n,i,a[N];
ll s[N],t[M<<1|5];
set<int>S;
inline void add(int i,int v){
	for(i+=M;t[i]+=v,i>>=1;);
}
inline int ask(ll x){
	int i=1;
	for(;i<M;)if(x<=t[i<<1])i=i<<1;else x-=t[i<<1],i=i<<1|1;
	return *S.upper_bound(i-M);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>s[i],add(i,i),S.insert(i);;
	for(i=n;i;--i){
		a[i]=ask(s[i]);
		add(a[i],-a[i]);S.erase(a[i]);
	}
	for(i=1;i<=n;++i)cout<<a[i]<<' ';cout<<endl;
}