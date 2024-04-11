#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int pre[1000010];
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
vector<int> vec;
int unin(int a,int b,int c){
	// cout<<"unin"<<a<<" "<<b<<" "<<c<<endl;
	int fa=find(a);
	int fb=find(b);
	if(fa==fb){
		return 0;
		// cout<<a<<" "<<b<<"??"<<endl;
	}
	pre[fa]=fb;
	vec.push_back(c);
	return 1;
}
ll mypow(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1)ret = ret * a%mod;
		a = a * a%mod; b >>= 1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;cin>>n>>k;
	int ans=0;
	for(int i=1;i<=k+1;i++) pre[i]=i;
	for(int i=1;i<=n;i++){
		int tag;cin>>tag;
		if(tag==1){
			int x;cin>>x;
			ans+=unin(x,k+1,i);
		}
		else{
			int a,b;cin>>a>>b;
			ans+=unin(a,b,i);
		}
	}
	cout<<mypow(2,ans)<<" "<<ans<<endl;
	for(auto &it:vec) cout<<it<<" ";
	cout<<endl;
}