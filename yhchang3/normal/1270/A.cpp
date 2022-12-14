#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,k1,k2;
		bool ex=false;
		cin>>n>>k1>>k2;
		for(int i=1;i<=k1;i++){
			int x;
			cin>>x;
			if(x==n)	ex=true;
		}
		for(int i=1;i<=k2;i++){
			int x;
			cin>>x;
		}
		if(ex)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
}