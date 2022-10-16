#include <bits/stdc++.h>
using namespace std;
int m, n;
string s;
int f[2001][2001];
int g[2001][2001];
const int base=1000000007;
void add(int &x, int y){
	x+=y;
	if(x>=base) x-=base;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	n-=m;
	cin>>s;
	int low=0;
	int sum=0;
	for(auto &c: s) if(c=='('){
		sum++;
	}
	else{
		sum--;
		low=min(low, sum);
	}
	low=-low;
	if(low>n){
		cout<<0;
		return 0;
	}
	f[n][0]=1;
	for(int i=n; i>=0; i--){
		for(int j=0; j<=n; j++) if(f[i][j]){
			if(i&&(j<n)) add(f[i-1][j+1], f[i][j]);
			if(i&&(j)) add(f[i-1][j-1], f[i][j]);
			if((j>=low)&&(j+sum<=n)) add(g[i][j+sum], f[i][j]);
		}
	}
	for(int i=n; i>=0; i--){
		for(int j=0; j<=n; j++) if(g[i][j]){
			if(i&&(j<n)) add(g[i-1][j+1], g[i][j]);
			if(i&&(j)) add(g[i-1][j-1], g[i][j]);
		}
	}
	cout<<g[0][0]<<'\n';
}