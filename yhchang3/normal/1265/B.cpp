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
		vector<int> pos(n+1);
		for(int i=1,x;i<=n;i++){
			cin>>x;
			pos[x]=i;
		}
		int M=pos[1],m=pos[1];
		cout<<1;
		for(int i=2;i<=n;i++){
			M=max(M,pos[i]);
			m=min(m,pos[i]);
			cout<<(M-m==i-1);
		}
		cout<<'\n';
	}
}