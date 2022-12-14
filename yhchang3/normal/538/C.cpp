#include<bits/stdc++.h>
using namespace std;

int d[100001],h[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>d[i]>>h[i];
	int ans=max(h[1]+d[1]-1,h[m]+n-d[m]);
	for(int i=2;i<=m;i++){
		int cnt=0,l;
		if(h[i]<=h[i-1])
			cnt=h[i-1]-h[i],l=h[i-1];
		else
			cnt=h[i]-h[i-1],l=h[i];
		if(cnt>d[i]-d[i-1]){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		else ans=max(ans,(d[i]-d[i-1]-cnt)/2+l);

	}
	cout<<ans<<endl;
}