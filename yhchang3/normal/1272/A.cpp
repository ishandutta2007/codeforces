#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		cout<<max(abs(a-b)+abs(b-c)+abs(c-a)-4,0)<<'\n';
	}
}