#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--){
		int n,m;
		cin>>n>>m;
		int sum=0;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			sum+=x;
		}
		if(n==2||n!=m)
			cout<<-1<<'\n';
		else{
			cout<<sum*2<<'\n';
			for(int i=1;i<=n;i++)
				cout<<i<<' '<<i%n+1<<'\n';
		}
	}
}