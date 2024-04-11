#include <bits/stdc++.h>
using namespace std;
double f[10][10];
int h[10][10];
vector <pair <int, int>> order;
double ept[10][10000];
bool done[10][10000];
double E(int u, int v){
	if(done[u][v]) return ept[u][v];
	done[u][v]=1;
	if(u==0||v==0) return ept[u][v]=0;
	ept[u][v]=0;
	for(int j=1; j<=6; j++){
		if(j>u){
			ept[u][v]+=E(u, v-1);
		}
		else{
			ept[u][v]+=E(u-j, v-1);
		}
	}
	(ept[u][v]/=6)+=1;
	return ept[u][v];
}
int main(){
	// for(int i=0; i<10; i++) cerr<<setprecision(16)<<fixed<<E(i, 9999)<<' ';
	cerr<<'\n';
	for(int i=0; i<10; i++)	for(int j=0; j<10; j++) cin>>h[i][j];
	for(int i=0; i<10; i++) f[0][i]=E(i, 9999);
	for(int i=9; i>=0; i--){
		if(i%2){
			for(int j=0; j<10; j++) order.push_back({i, j});
		}
		else{
			for(int j=9; j>=0; j--) order.push_back({i, j});
		}
	}
	for(int p=89; p>=0; p--){
		for(int k=1; k<=6; k++){
			f[order[p].first][order[p].second]+=min(f[order[p+k].first][order[p+k].second], f[order[p+k].first-h[order[p+k].first][order[p+k].second]][order[p+k].second]);
		}
		(f[order[p].first][order[p].second]/=6)+=1;
	}
	cout<<setprecision(16)<<fixed<<f[9][0]<<'\n';
}