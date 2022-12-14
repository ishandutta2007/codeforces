#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int d=abs(a-b);
		int ans=d/5;
		if(d%5==0);
		else if(d%5<3)	ans++;
		else	ans+=2;
		cout<<ans<<'\n';
	}
}