#include<bits/stdc++.h>
using namespace std;

int a[200001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=2*n;i++)
			cin>>a[i];;
		unordered_map<int,int> m;
		int cnt=0;
		m[0]=0;
		for(int i=n+1;i<=2*n;i++){
			if(a[i]==1)
				cnt++;
			else
				cnt--;
			if(!m.count(cnt))
				m[cnt]=i-n;
		}
		cnt=0;
		int diff=0;
		for(int i=1;i<=2*n;i++)
			if(a[i]==1)
				diff++;
			else
				diff--;
		int ans=1e8;
		if(m.count(diff-cnt))
			ans=min(ans,m[diff-cnt]);
		for(int i=n;i>=1;i--){
			if(a[i]==1)
				cnt++;
			else
				cnt--;
			if(m.count(diff-cnt))
				ans=min(ans,m[diff-cnt]+(n-i+1));
		}
		cout<<ans<<'\n';
	}
}