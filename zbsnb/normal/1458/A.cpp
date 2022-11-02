#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000010],b[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	ll g=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			g=__gcd(g,abs(a[i]-a[1]));
		}
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		cout<<__gcd(a[1]+b[i],g)<<" ";
	}
}