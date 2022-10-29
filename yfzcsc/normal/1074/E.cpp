#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> O;
int a[50][50],vis[2510],n,m;
pii b[2510],B[10100];
vector<O>W;
int go(O v,int flg=0){
	if(flg==0)for(auto c:v)if(vis[c])return 0;
//	puts("OK");
	if(v.size()<4)exit(-1);
	for(int i=0;i<v.size();++i)
		B[i]=b[v[i]];
	for(int i=v.size()-1;i>=0;--i){
		int to=(i==0?v.size()-1:i-1);
		a[B[i].xx][B[i].yy]=v[to];
		b[v[to]]=B[i];
	}
	W.push_back(v);
	return 1;
}
void print(){
	printf("%d",W.size());
	for(auto c:W){
		printf("\n%d ",c.size());
		for(auto d:c)printf("%d ",d);
	}
}
void oak(vector<int> tree){
	if(tree.size()!=6)exit(-1);
	go(O{tree[0],tree[3],tree[4],tree[5],tree[2],tree[1]},1);
	go(O{tree[2],tree[5],tree[4],tree[3]},1);
	go(O{tree[3],tree[4],tree[0],tree[1]},1);
}
void fk(int x,int y,int x2,int y2,int dx,int dy){
	vector<int> wxh;
	for(int i=0;i<3;++i)wxh.push_back(a[x+dx*i][y+dy*i]);
	for(int i=0;i<3;++i)wxh.push_back(a[x2+dx*i][y2+dy*i]);
	oak(wxh);
}
void swp(int x,int y,int nx,int ny){
	if(x>nx)swap(x,nx);
	if(y>ny)swap(y,ny);
//	puts("OK");
	if(x==nx){
		int x1=0,x2=0;
		if(nx==1)x1=x+1,x2=x;
		else x1=x-1,x2=x;
		if(ny==m)fk(x1,ny,x2,ny,0,-1);
		else fk(x1,y,x2,y,0,1);
	} else {
		int y1=0,y2=0;
		if(ny==1)y1=y+1,y2=y;
		else y1=y-1,y2=y;
		if(nx==n)fk(nx,y1,nx,y2,-1,0);
		else fk(x,y1,x,y2,1,0);
	}
}
void walk(int x,int y,int nx,int ny){
	while(x!=nx||y!=ny){
//		printf("[%d,%d]",x,y);
		if(x!=nx&&!vis[a[(x>nx?x-1:x+1)][y]]){
			int d=(x>nx?-1:1);
			if(y!=m){
				if(!go(O{a[x][y],a[x+d][y],a[x+d][y+1],a[x][y+1]}))
					swp(x,y,x+d,y);
			} else {
				if(!go(O{a[x][y],a[x+d][y],a[x+d][y-1],a[x][y-1]}))
					swp(x,y,x+d,y);
			}
			x+=d; 
		} else if(y!=ny&&!vis[a[x][(y>ny?y-1:y+1)]]){
			int d=(y>ny?-1:1);
			if(x!=n){
				if(!go(O{a[x][y],a[x][y+d],a[x+1][y+d],a[x+1][y]}))
					swp(x,y,x,y+d);
			} else {
				if(!go(O{a[x][y],a[x][y+d],a[x-1][y+d],a[x-1][y]}))
					swp(x,y,x,y+d);
			}
			y+=d;
		} else exit(2);
	}
}
void printa(){
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=m;++j)
			printf("%d ",a[i][j]);
	puts(">>>");
}
void chka(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]!=(i-1)*m+j)puts("WA"),exit(-1);
	puts("AC");
	int sum=0;
	for(auto c:W)sum+=c.size();
	printf("[used:%d]",sum);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	/*
	n=20,m=20;
	vector<int>v;
	for(int i=1;i<=n*m;++i)v.push_back(i);
	reverse(v.begin(),v.end());
	//random_shuffle(v.begin(),v.end());
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=v[(i-1)*m+j-1];*/
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			b[a[i][j]]=pii(i,j);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			int J=(i-1)*m+j;
			walk(b[J].xx,b[J].yy,i,j);
//			printa();
			vis[J]=1;
//			return 0;
		}
//	chka();
	print();
}