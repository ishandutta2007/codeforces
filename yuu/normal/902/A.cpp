#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[101];
int y[101];
bool g[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++)	cin>>x[i]>>y[i];
	g[0]=1;
	for(int i=1; i<=n; i++) if(g[x[i]]) for(int j=x[i]+1; j<=y[i]; j++) g[j]=1;
	if(g[m]) cout<<"YES\n";
	else cout<<"NO\n";
}