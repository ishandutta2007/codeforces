#include <bits/stdc++.h>
using namespace std;
int n, k;
vector <int> q;
int main(){
	cin>>n>>k;
	int ans=0;
	int spec=0;
	for(int i=1, t, pos=0, first=1; i<=n; i++){
		cin>>t;
		if(t<0){
			ans+=2;
			k--;
			if(!first) q.push_back(pos);
			first=0;
			pos=0;
		}
		else pos++;
		if(i==n) spec=pos;
	}
	if(k<0) ans=-1;
	else{
		sort(q.begin(), q.end());
		int mx=spec<=k;
		for(int i=0, sum=0; i<q.size(); i++){
			sum+=q[i];
			if(sum<=k) mx=max(mx, (i+1)*2);
			if(sum+spec<=k) mx=max(mx, (i+1)*2+1);
		}
		ans-=mx;
		ans=max(ans, 0);
	}
	cout<<ans<<'\n';
	return 0;
}