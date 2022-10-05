#include<bits/stdc++.h>
using namespace std;
vector<int>u,v;
int m,fa[333333][20]={0},dep[333333]={0},mx,to=1;
int dis(int x,int y){
	int t=dep[x]+dep[y];
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--){
		if (dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
		}
	}
	if (x==y) return t-dep[x]*2;
	for (int i=19;i>=0;i--){
		if (fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	x=fa[x][0];
	return t-dep[x]*2;
}
int main(){
	scanf("%d",&m);
	dep[1]=1;
	for (int y=2,x;m--;y++){
		scanf("%d",&x);
		fa[y][0]=x;dep[y]=dep[x]+1;
		for (int i=1;i<20;i++) fa[y][i]=fa[fa[y][i-1]][i-1];
		if (y==2){
			u.push_back(1);v.push_back(2);
			mx=1;
		}else{
			if (dis(u[0],y)<dis(v[0],y)) {swap(u,v);to^=1;}
			if (dis(u[0],y)>mx){ 
				if (dis(v[0],y)>mx&&to) {swap(u,v);to^=1;}
				mx++;
				for (int i=0;i<(int)v.size();i++){
					if (dis(y,v[i])==mx){
						u.push_back(v[i]);
					}
				}
				v.clear();v.push_back(y);
			}else if (dis(u[0],y)==mx){
				if (dis(v[0],y)==mx&&to) u.push_back(y);
				else v.push_back(y);
			}
		}
		printf("%d\n",(int)u.size()+v.size());
	}
}