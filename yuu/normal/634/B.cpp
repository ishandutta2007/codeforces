#include <bits/stdc++.h>
using namespace std;
long long x, s;
vector <int> dx, ds;
bool done[51][2];
long long f[51][2];
long long F(int u, int b){
	if(done[u][b]) return f[u][b];
	done[u][b]=1;
	if(u==50) return f[u][b]=(b==0);
	for(int x=0; x<2; x++){
		int y=dx[u]^x;
		if((x+y+b)%2==ds[u]) f[u][b]+=F(u+1, (x+y+b)/2);
	}
	return f[u][b];
}
int main(){
	cin>>s>>x;
	int minus=(s==x)?2:0;
	for(int i=0; i<50; i++){
		dx.push_back(x%2);
		x/=2;
	}
	for(int i=0; i<50; i++){
		ds.push_back(s%2);
		s/=2;
	}
	cout<<F(0, 0)-minus<<'\n';
}