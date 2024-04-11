#include<bits/stdc++.h>
#define N 60
using namespace std;
struct Data{
	int x1,y1,x2,y2;
	Data(){}
	Data(int x1,int y1,int x2,int y2):
		x1(x1),y1(y1),x2(x2),y2(y2){}
};
int n,m,a[N][N],tg[N],b[N][N];
vector<Data>out,out2; 
void mov(int x1,int y1,int x2,int y2,vector<Data>& v){
	while(x1!=x2||y1!=y2){
		if(x1<x2)v.push_back(Data(x1,y1,x1+1,y1)),++x1;
		else if(x1>x2)v.push_back(Data(x1,y1,x1-1,y1)),--x1;
		else if(y1<y2)v.push_back(Data(x1,y1,x1,y1+1)),++y1;
		else v.push_back(Data(x1,y1,x1,y1-1)),--y1;
	}
}
int sol(int a[N][N],vector<Data>& out){
	int l=1;
	for(int i=1;i<=n;++i){
		int to[N],c=0;
		for(int j=1;j<=n;++j)if(a[i][j])
			to[a[i][j]]=c++;
		while(1){
			int cnt=0;
			for(int j=1;j<=n;++j)if(a[i][j]){
				int can=0;
				if(j==to[a[i][j]]+l)
					continue;
				cnt++;
				for(int k=min(to[a[i][j]]+l,j);k<=max(to[a[i][j]]+l,j);++k)
					if(a[i][k])can++;
				if(can==1){
					mov(i,j,i,to[a[i][j]]+l,out);
					swap(a[i][j],a[i][to[a[i][j]]+l]);
				}
			}
			if(!cnt)break;
		}
		l+=c;
	}
	/*
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=n;++j)
			printf("[%d]",a[i][j]);
	puts("<<<");*/
	l=1;
	int tg[N]={0};
	for(int i=1;i<=n;++i){
		int s=0;
		for(int j=1;j<=n;++j)if(a[i][j]&&!tg[a[i][j]])
			mov(i,j,l,j,out),tg[a[i][j]]=1,swap(a[i][j],a[l++][j]);
	}
	/*
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=n;++j)
			printf("[%d]",a[i][j]);
	puts("<<<");*/
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)
		scanf("%d%d",&x,&y),a[x][y]=i;
	for(int i=1,x,y;i<=m;++i)
		scanf("%d%d",&x,&y),b[y][x]=i;
	sol(a,out),sol(b,out2);
	for(auto& c:out2)swap(c.x1,c.y1),swap(c.x2,c.y2);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(a[i][j])
			for(int k=1;k<=n;++k)
				for(int l=1;l<=n;++l)if(b[l][k]==a[i][j]){
//					printf("{%d,%d}->{%d,%d}\n",i,j,k,l);
					mov(i,j,i,l,out);
				}
//	for(int i=1;i<=n;++i,puts(""))for(int j=1;j<=n;++j)printf("[%d]",a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(a[i][j])
			for(int k=1;k<=n;++k)
				for(int l=1;l<=n;++l)if(b[l][k]==a[i][j]){
					mov(i,l,k,l,out);
				}
	reverse(out2.begin(),out2.end());
	for(auto c:out2)out.push_back(Data(c.x2,c.y2,c.x1,c.y1));
	printf("%d\n",out.size());
	for(auto c:out)printf("%d %d %d %d\n",c.x1,c.y1,c.x2,c.y2);
}