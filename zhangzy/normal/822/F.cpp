#include<bits/stdc++.h>
using namespace std;
int n,hea[233];
vector<int>r[233],pos[233];

void pri(int p,int u,int v,double t){
	if (t<=1){
		printf("1 %d %d %d %.10lf\n",p,v,u,(double)1-t);
	}else{
		printf("1 %d %d %d %.10lf\n",p,u,v,(double)2-t);
	}
}
	
void dfs(int x,int fa,double tim){
	while (tim>=2) tim-=2;
	int sz=r[x].size();
	double e=(double)2/(double)sz;
	int y;
	for (int i=0;i<sz;i++){
		y=r[x][i];
		if (y!=fa){
			tim+=e;
			while (tim>=2) tim-=2;
			pri(pos[x][i],x,y,tim);
			dfs(y,x,tim+1.0);
		}
	}
}

int main(){
	int x,y;
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		r[x].push_back(y);
		pos[x].push_back(i);
		r[y].push_back(x);
		pos[y].push_back(i);
	}
	printf("%d\n",n-1);
	dfs(1,0,0.0);
}