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
		map<int,int> m;
		int ans=300000;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			if(m.find(x)==m.end())
				m[x]=i;
			else{
				ans=min(ans,i-m[x]+1);
				m[x]=i;
			}
		}
		if(ans==300000)
			ans=-1;
		cout<<ans<<'\n';
	}
}