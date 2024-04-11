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
		int delta = abs(a-b);
		if(a>b){
			a-=2*delta;
			b-=delta;
		}
		else{
			b-=2*delta;
			a-=delta;
		}
		if(a>=0&&b>=0&&a%3==0&&b%3==0)
			cout<<"Yes"<<'\n';
		else
			cout<<"No"<<'\n';
		
	}
}