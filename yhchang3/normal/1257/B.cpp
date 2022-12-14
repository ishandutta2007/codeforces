#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int x,y;
		cin>>x>>y;
		if(x>=4)
			cout<<"YES"<<endl;
		else if(x==1)
			cout<<(y==1?"YES":"NO")<<endl;
		else
			cout<<(y<=3?"YES":"NO")<<endl;
	}
}