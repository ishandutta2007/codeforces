#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
typedef vector<int>V;
typedef pair<int,int>pii;
void exgcd(int a,int b,int&x,int&y){if(!b)x=1,y=0;else exgcd(b,a%b,y,x),y-=a/b*x;}
inline int inv(int p,int q){int x,y;exgcd(p,q,x,y);return (x%q+q)%q;}
unordered_map<int,pair<V,V>>mp;
int n,m,im,in,x,y,g;
ll ans,z;
inline ll calc(map<int,int>mp,vector<int>v,int m,int n,int im){
	static int a[N],b[N];int l=0,i;ll mx=0;
	for(auto u:mp)a[++l]=u.first,b[l]=u.second;
	for(i=1;i<l;++i)b[i+1]=min((ll)b[i+1],b[i]+1ll*m*(a[i+1]-a[i]));b[1]=min((ll)b[1],b[l]+1ll*(a[1]+n-a[l])%n*m);
	for(i=1;i<l;++i)b[i+1]=min((ll)b[i+1],b[i]+1ll*m*(a[i+1]-a[i]));b[1]=min((ll)b[1],b[l]+1ll*(a[1]+n-a[l])%n*m);
	a[l+1]=a[1]+n;
	for(i=1;i<=l;++i)if(a[i+1]>a[i]+1)mx=max(mx,b[i]+1ll*m*(a[i+1]-a[i]-1));
	for(int x:v)mp[1ll*x*im%n]=0;
	for(auto u:mp)mx=max(mx,(ll)u.second);
	return mx;
}
inline void upd(map<int,int>&mp,int x,int y){if(!mp.count(x))mp[x]=y;else mp[x]=min(mp[x],y);}
inline void solve(V a,V b,int zz){
	sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end());
	sort(b.begin(),b.end());b.erase(unique(b.begin(),b.end()),b.end());
	if(a.size()==n && b.size()==m)return;
	map<int,int>A,B;
	for(int x:a)upd(A,1ll*x*im%n,x),upd(B,1ll*x*in%m,x);
	for(int x:b)upd(B,1ll*x*in%m,x),upd(A,1ll*x*im%n,x);
	ans=max(ans,zz+g*max(calc(A,a,m,n,im),calc(B,b,n,m,in)));
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;g=__gcd(n,m);n/=g;m/=g;im=inv(m,n);in=inv(n,m);
	cin>>x;for(;x--;)cin>>y,mp[y%g].first.push_back(y/g);
	cin>>x;for(;x--;)cin>>y,mp[y%g].second.push_back(y/g);
	if(mp.size()<g)ans=-1;else for(auto u:mp)solve(u.second.first,u.second.second,u.first);
	cout<<ans<<endl;
	return 0;
}