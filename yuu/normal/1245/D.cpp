#include <bits/stdc++.h>
using namespace std;
int n;
int x[2001];
int y[2001];
long long c[2001];
long long k[2001];
bool done[2001];
int trace[2001];
vector <int> v;
vector <pair <int, int>> e;
int main(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>x[i]>>y[i];
	for(int i=1; i<=n; i++) cin>>c[i];
	for(int i=1; i<=n; i++) cin>>k[i];
	long long ans=0;
	for(int i=1; i<=n; i++){
		int best=-1;
		for(int j=1; j<=n; j++) if(!done[j]){
			if(best==-1) best=j;
			else if(c[j]<c[best]) best=j;
		}
		done[best]=1;
		ans+=c[best];
		if(trace[best]) e.push_back({trace[best], best});
		else v.push_back(best);
		for(int j=1; j<=n; j++) if(!done[j]){
			int dist=abs(x[best]-x[j])+abs(y[best]-y[j]);
			if(c[j]>(k[best]+k[j])*dist){
				c[j]=(k[best]+k[j])*dist;
				trace[j]=best;
			}
		}
	}
	cout<<ans<<'\n';
	cout<<v.size()<<'\n';
	for(auto &x: v) cout<<x<<' ';
	cout<<'\n';
	cout<<e.size()<<'\n';
	for(auto &x: e) cout<<x.first<<' '<<x.second<<'\n';
}