#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int a,b,c,r;
		cin>>a>>b>>c>>r;
		if(a>b)	swap(a,b);
		int d=min(b,c+r)-max(a,c-r);
		if(d>=0)
			cout<<b-a-d<<'\n';
		else
			cout<<b-a<<'\n';
	}
}