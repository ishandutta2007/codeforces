#include<bits/stdc++.h>
using namespace std;

int a[200010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		bool ok=false;
		for(int i=1;i<n;i++)
			if(abs(a[i]-a[i+1])>1){
				ok=true;
				cout<<"YES"<<'\n';
				cout<<i<<' '<<i+1<<'\n';
				break;
			}
		if(!ok)
			cout<<"NO"<<'\n';
	}
}