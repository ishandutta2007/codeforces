#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int px[100000];
int py[100000];
map <int, vector <int>> ma;
map <int, vector <int>> an;
long long ans[100000];
int main(){
	cin>>n>>m>>k;
	for(int i=0; i<k; i++){
		cin>>px[i]>>py[i];
		ma[px[i]-py[i]].push_back(i);
		an[px[i]+py[i]].push_back(i);
		ans[i]=1e18;
	}
	long long now=0;
	int cx=1, cy=1;
	int x=0, y=0;
	while(true){
		if(cx*cy==1){//ma diag
			int diag=x-y;
			auto it=ma.find(diag);
			if(it!=ma.end()){
				for(int i: it->second) ans[i]=min(ans[i], now+abs(px[i]-x));
				ma.erase(it);
			}
		}
		else{//an diag
			int diag=x+y;
			auto it=an.find(diag);
			if(it!=an.end()){
				for(int i: it->second) ans[i]=min(ans[i], now+abs(px[i]-x));
				an.erase(it);
			}
		}
		int moves=1e9;
		if(cx==1) moves=min(moves, n-x);
		else moves=min(moves, x);
		if(cy==1) moves=min(moves, m-y);
		else moves=min(moves, y);
		x+=cx*moves;
		y+=cy*moves;
		if((x==0||x==n)&&(y==0||y==m)) break;
		if(x==0||x==n) cx=-cx;
		if(y==0||y==m) cy=-cy;
		now+=moves;
	}
	for(int i=0; i<k; i++) if(ans[i]==1e18) ans[i]=-1;
	for(int i=0; i<k; i++) cout<<ans[i]<<"\n";
}