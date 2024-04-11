#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int cnt[20][20];
int f[1<<20];
int main(){
	cin>>n>>m>>s;
	for(auto &x: s) x-='a';
	for(int i=1; i<n; i++){
		cnt[s[i-1]][s[i]]++;
		cnt[s[i]][s[i-1]]++;
	}
	for(int i=0; i<(1<<m); i++) f[i]=2e9;
	f[0]=0;
	for(int i=0; i<(1<<m); i++){
		int now=__builtin_popcount(i);
		for(int j=0; j<m; j++) if((i&(1<<j))==0){
			int cost=0;
			for(int k=0; k<m; k++) if(j!=k){
				if(i&(1<<k)) cost+=cnt[j][k];
				else cost-=cnt[j][k];
			}
			f[i|(1<<j)]=min(f[i|(1<<j)], f[i]+cost*now);
		}
	}
	cout<<f[(1<<m)-1]<<'\n';
}