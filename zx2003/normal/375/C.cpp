#include<bits/stdc++.h>
const int N=22,f1[4]={0,1,0,-1},f2[4]={-1,0,1,0},S=600000;
char c[N][N];
int n,m,tcnt,cnt,i,j,k,idb[N][N],cost[N];
struct state{
	int x,y,pd,s;
	int hsh(){
		return 260*(5*(x*m+y)+pd)+s;
	}
}q[S];
int step[S],t,w;
int main(){
	scanf("%d%d",&n,&m);
	w=1;
	memset(step,-1,sizeof step);
	memset(idb,-1,sizeof idb);
	for(i=1;i<=n;++i){
		scanf("%s",c[i]+1);
		for(j=1;j<=m;++j){
			if(isdigit(c[i][j])){
				idb[i][j]=c[i][j]-'1';
				++cnt;
			}
			if(c[i][j]=='S'){
				c[i][j]='.';
				q[1].x=i,q[1].y=j,q[1].pd=4;
				step[q[1].hsh()]=0;
			}
		}
	}
	for(i=1;i<=cnt;++i)scanf("%d",cost+i);tcnt=cnt;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)if(c[i][j]=='B')idb[i][j]=cnt++;
	for(;t<w;){
		state u=q[++t],v;
		if(u.x==2 && u.y==2){
			++t,--t;
		}
		for(i=0;i<4;++i)if((i^u.pd)!=2){
			v=u;v.x+=f1[i];v.y+=f2[i];v.pd=i;
			if(c[v.x][v.y]!='.')continue;
			if(i==1)
				for(j=u.y+1;j<=m;++j){
					if(~idb[u.x][j])
						v.s^=1<<idb[u.x][j];
				}
			if(i==3)
				for(j=v.y+1;j<=m;++j)
					if(~idb[v.x][j])
						v.s^=1<<idb[v.x][j];
			if(!~step[v.hsh()]){
				step[v.hsh()]=step[u.hsh()]+1,q[++w]=v;
				if(w==7){
					++t,--t;
				}
			}
		}
	}
	int ans=0;
	state z=q[1];
	for(i=0;i<1<<tcnt;++i){
		int sum=0,a;
		for(j=0;j<tcnt;++j)if(i>>j&1)sum+=cost[j+1];
		for(j=0;j<4;++j){
			z.pd=j;z.s=i;
			a=step[z.hsh()];
			if(~a && sum-a>ans)ans=sum-a;
		}
	}
	printf("%d\n",ans);
	return 0;
}