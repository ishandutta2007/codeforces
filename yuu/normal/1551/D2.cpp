#include <bits/stdc++.h>
using namespace std;
int d[100][100];
char ans[10000];
vector <int> near[10000];
int n, m, k;
const int dx[]={1, -1, 0, 0};
const int dy[]={0, 0, 1, -1};
void solve(){
	cin>>n>>m>>k;
	int id=0;
	if(n%2==0){//always try to place vertical first
		for(int i=0; i<n; i+=2) for(int j=0; j<m; j++){
			d[i][j]=d[i+1][j]=id;
			id++;
		}
	}
	else{
		for(int i=0; i<n; i++) for(int j=0; j<m; j+=2){
			d[i][j]=d[i][j+1]=id;
			id++;
		}
		k=n*m/2-k;
	}
	vector <pair <int, int>> rotate;
	for(int i=1; i<n; i+=2) for(int j=1; j<m; j+=2){
		rotate.emplace_back(i-1, j-1);
	}
	if((k%2)||(k>rotate.size()*2)){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	//return;
	k/=2;
	for(int i=0; i<k; i++){
		int x=rotate[i].first;
		int y=rotate[i].second;
		swap(d[x][y], d[x+1][y+1]);
	}
	for(int i=0; i<id; i++) near[i].clear();
	for(int i=0; i<n; i++) for(int j=0; j<m; j++){
		for(int v=0; v<4; v++){
			int x=i+dx[v];
			int y=j+dy[v];
			if(x<0||x>=n) continue;
			if(y<0||y>=m) continue;
			if(d[x][y]>=d[i][j]) continue;
			near[d[i][j]].push_back(d[x][y]);
		}
	}
	for(int i=0; i<id; i++){
		set <char> used;
		for(int &x: near[i]) used.insert(ans[x]);
		ans[i]='a';
		while(used.find(ans[i])!=used.end()) ans[i]++;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cout<<ans[d[i][j]];
		cout<<'\n';
	}
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}