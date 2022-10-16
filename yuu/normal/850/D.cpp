#include <bits/stdc++.h>
using namespace std;
const int maxplayer=64;
const int maxsum=maxplayer*(maxplayer-1)/2;
int a[31];
int f[maxplayer+1][31][maxsum+1];
int m;
void get_tournament(vector <int> d){
  int n=d.size();
	int c[n][n];
	bool done[n];
	for(int i=0; i<n; i++) done[i]=0;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) c[i][j]=0;
	while(true){
		int u=-1;
		for(int i=0; i<n; i++) if(!done[i]) if((u==-1)||(d[i]<d[u])) u=i;
		if(u==-1) break;
    done[u]=1;
		while(d[u]){
			int v=-1;
			for(int i=0; i<n; i++) if(!done[i]) if((c[i][u]==0)&&(c[u][i]==0)){
				if(v==-1) v=i;
				if(d[i]<d[v]) v=i;
			}
			c[u][v]=1;
			d[u]--;
		}
    for(int i=0; i<n; i++) if(!done[i]) if(c[u][i]==0){
      c[i][u]=1;
      d[i]--;
    }
	}
	cout<<d.size()<<'\n';
	for(int i=0; i<d.size(); i++){
		for(int j=0; j<d.size(); j++) cout<<c[i][j];
		cout<<'\n';
	}
}
void get_ans(int i, int j, int k){
	vector <int> degs;
	while(i){
		degs.push_back(a[j]);
		k-=a[j];
		if(f[i][j][k+a[j]]==1) j--;
		i--;
	}
	get_tournament(degs);
	exit(0);
}
int main(){
	cin>>m;
	for(int i=0; i<m; i++) cin>>a[i];
	sort(a, a+m);
	for(int i=0; i<maxplayer; i++) for(int j=0; j<31; j++) for(int k=0; k<=maxsum; k++) f[i][j][k]=-1;
	f[1][0][a[0]]=0;
	for(int i=1; i<maxplayer; i++){
		for(int j=0; j<m; j++) for(int k=i*(i-1)/2; k<=maxsum; k++) if(f[i][j][k]>=0){
			//another a[j]
			if(k+a[j]<=maxsum)	f[i+1][j][k+a[j]]=0;//same
			//change to a[j+1]
			if(j<m) if(k+a[j+1]<=maxsum) f[i+1][j+1][k+a[j+1]]=1;//changed
		}
		if(i*(i-1)/2<=maxsum) if(f[i][m-1][i*(i-1)/2]>=0) get_ans(i, m-1, i*(i-1)/2);
	}
	cout<<"=(";
}