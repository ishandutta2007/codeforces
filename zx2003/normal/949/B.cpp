#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;int q;
ll ask(ll a,ll b){
	if(a&1){
		if(b&1)return b/2+1;
			else return ask(a>>1,b==2?a>>1:(b>>1)-1)+(a/2+1);
	}else{
		if(b&1)return b/2+1;
			else return ask(a>>1,b>>1)+(a/2);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	while(q--){
		cin>>x;
		cout<<ask(n,x)<<'\n';
	}
	return 0;
}