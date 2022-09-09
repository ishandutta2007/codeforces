#include<cstdio>
#include<vector>
const int N=70005;
int n,i,j,x,k,mi,id;
char c[N][15];
struct Trie{
	int ch[N*46][10],xb,val[N*46];
	inline void ins(char*c,int l,int v){
		register int u=0,i=0,x;
		for(;i<l;++i){
			x=c[i]^48;
			if(!ch[u][x])ch[u][x]=++xb;
			u=ch[u][x];
			val[u]=val[u] && val[u]!=v?-1:v;
		}
	}
	int find(char*c,int l,int v){
		register int u=0,i=0;
		for(;i<l;++i){
			u=ch[u][c[i]^48];
			if(val[u]==v)return i;
		}
		return -1;
	}
}t;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%s",c[i]+1);
		for(j=1;j<=9;++j)t.ins(c[i]+j,9-j+1,i);
	}
	for(i=1;i<=n;++i){
		mi=9;
		for(j=1;j<=9;++j){
			x=t.find(c[i]+j,9-j+1,i);
			if(x!=-1 && x<mi)mi=x,id=j;
		}
		for(k=id;k<=id+mi;++k)putchar(c[i][k]);
		putchar('\n');
	}
	return 0;
}