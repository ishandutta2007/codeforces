#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		long long int sum=0,xo=0;
		for(int i=1;i<=n;i++){
			int u;
			cin>>u;
			sum+=u;
			xo^=u;
		}
		cout<<3<<'\n';
		long long int f=(1LL<<55)+xo;
		xo^=f;
		sum+=f;
		cout<<f<<' '<<(xo*2-sum)/2<<' '<<(xo*2-sum)/2<<'\n';
	}
}