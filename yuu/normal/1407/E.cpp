#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> h[500001][2];
bool done[500001];
int f[500001];
int r[500001][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1, u, v, t; i<=m; i++){
		cin>>u>>v>>t;
		h[v][t].push_back(u);
	}
	for(int i=1; i<=n; i++) r[i][0]=r[i][1]=1e9;
	{
		queue <int> q;
		q.push(n);
		f[n]=3;
		done[n]=1;
		r[n][0]=r[n][1]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for (int b=0; b<2; b++){
				for(int v: h[u][b]){
					f[v]|=1<<b;
					r[v][b]=min(r[v][b], max(r[u][0], r[u][1])+1);
					if((!done[v])&&(f[v]==3)){
						done[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
	if(f[1]!=3) cout<<"-1\n";
	else cout<<max(r[1][0], r[1][1])<<'\n';
	for(int i=1; i<=n; i++) cout<<"01"[r[i][0]<r[i][1]];
}