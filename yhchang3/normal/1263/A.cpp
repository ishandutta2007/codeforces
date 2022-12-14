#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int r,g,b;
		cin>>r>>g>>b;
		int m=max(max(r,g),b),s=r+g+b;
		if(m*2<=s)
			cout<<s/2<<'\n';
		else
			cout<<s-m<<'\n';
	}
}