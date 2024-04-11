#include <bits/stdc++.h>
using namespace std;
int n;
map <int, int> top, bot;
int main(){
	cin>>n;
	for(int i=1, a, b; i<=n; i++){
		cin>>a;
		top[a]++;
		cin>>b;
		if(b!=a){
			bot[b]++;
			top[b]+=0;
		}
	}
	int ans=n+1;
	for(auto x: top){
		int a=x.first;
		int t=x.second;
		int b=bot[a];
		if((t+b)*2<n) continue;
		if(t*2>=n){
			ans=0;
			break;
		}
		ans=min(ans, max(0, (n+1)/2-t));
	}
	if(ans==n+1) ans=-1;
	cout<<ans<<'\n';
}