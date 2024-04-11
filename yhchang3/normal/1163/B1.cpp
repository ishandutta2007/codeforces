#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
int cnt[100001],M,ans,n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(m[x]!=0)
			cnt[m[x]]--;
		m[x]++;
		cnt[m[x]]++;
		M=max(M,m[x]);
		if(M==1)
			ans=i;
		else if(i-1==cnt[M]*M||i-M==cnt[M-1]*(M-1))
			ans=i;
	}
	cout<<ans<<endl;
}