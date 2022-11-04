#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int head[N],tot,n;
struct edge{int to,next;}e[N*2];
struct LZH{
	ll d[4][2][2];
	LZH(){
		memset(d,0,sizeof(d));
	}
};
LZH operator *(LZH a,LZH b){
	LZH c;
	for (int aj=0;aj<2;aj++)
		for (int bj=0;bj+aj<2;bj++)
			for (int ak=0;ak<2;ak++)
				for (int bk=0;bk<=ak;bk++){
					c.d[0][aj+bj][ak^bk]+=a.d[0][aj][ak]*b.d[0][bj][bk];
					c.d[1][aj+bj][ak^bk]+=a.d[1][aj][ak]*b.d[0][bj][bk];
					c.d[1][aj+bj][ak^bk]+=a.d[0][aj][ak]*b.d[1][bj][bk];
					c.d[2][aj+bj][ak^bk]+=a.d[2][aj][ak]*b.d[0][bj][bk];
					c.d[2][aj+bj][ak^bk]+=a.d[0][aj][ak]*b.d[2][bj][bk];
					c.d[3][aj+bj][ak^bk]+=a.d[3][aj][ak]*b.d[0][bj][bk];
					c.d[3][aj+bj][ak^bk]+=a.d[0][aj][ak]*b.d[3][bj][bk];
					c.d[3][aj+bj][ak^bk]+=a.d[1][aj][ak]*b.d[1][bj][bk];
					c.d[3][aj+bj][ak^bk]+=a.d[2][aj][ak]*b.d[2][bj][bk];
				}
	return c;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void init(LZH &c){
	c.d[0][0][1]=1;
	c.d[1][0][0]=1;
	c.d[2][0][1]=1;
}
void cut(LZH &c){
	c.d[1][1][0]+=c.d[1][0][0];
	c.d[2][1][0]+=c.d[2][0][0];
}
LZH f[N];
void dfs(int x,int fa){
	init(f[x]);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			f[x]=f[x]*f[e[i].to];
		}
	cut(f[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	printf("%I64d\n",f[1].d[3][1][0]);
}
/*p[i][j][k]
k:1 
k:0 
j: 
i:
0  
1  
2  
3 2*/