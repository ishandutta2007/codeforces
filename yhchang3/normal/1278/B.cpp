#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		int ans=0;
		if(a>b)
			swap(a,b);
		while(a<b){
			ans++;
			a+=ans;
		}
		while((a+b)&1){
			ans++;
			a+=ans;
		}
		cout<<ans<<'\n';
	}
}