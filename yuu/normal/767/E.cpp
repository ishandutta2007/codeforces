#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001];
int c[100001];
int w[100001];
bool pick[100001];
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) c[i]=a[i]%100;
	for(int i=1; i<=n; i++){
		cin>>w[i];
		w[i]=w[i]*(100-c[i]);
	}
	long long ans=0;
	for(int i=1; i<=n; i++) if(c[i]){
		c[i]%=100;
		m-=c[i];
		q.push({w[i], i});
		if(m<0){
			ans+=q.top().first;
			m+=100;
			q.pop();
		}
		// cerr<<i<<' '<<m<<' '<<q.size()<<' '<<ans<<'\n';
	}
	while(!q.empty()){
		pick[q.top().second]=1;
		q.pop();
	}
	cout<<ans<<'\n';
	for(int i=1; i<=n; i++) if(pick[i]) cout<<a[i]/100<<' '<<c[i]<<'\n'; else cout<<(a[i]-1)/100+1<<' '<<"0\n";
}