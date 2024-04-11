#include <bits/stdc++.h>
using namespace std;
int n, k, b, c;
int x[200001];
priority_queue <long long> q; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k>>b>>c;
	for(int i=1; i<=n; i++){
		cin>>x[i];
		x[i]+=1e9;
	}
	sort(x+1, x+n+1);
	b=min(b, c*5);
	long long ans=1e18;
	for(int md=0; md<5; md++){
		long long sum=0;
		while(!q.empty()) q.pop();
		for(int i=1; i<=n; i++){
			long long d=md-(x[i]%5);
			if(d<0) d+=5;
			long long next=x[i]+d;
			d=-(next/5)*b+d*c;
			sum+=d;
			q.push(d);
			if(q.size()>k){
				sum-=q.top();
				q.pop();
			}
			if(q.size()==k)	ans=min(ans, (next/5)*b*k+sum);
		}
	}
	cout<<ans<<'\n';
}