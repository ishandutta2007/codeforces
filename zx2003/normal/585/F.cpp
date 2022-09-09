#include<bits/stdc++.h>
const int N=55,S=50005,mo=1e9+7;
struct ACM{
int ch[S][10],fail[S],xb;
bool b[S];
inline void ins(char*c,int l){
	int u=0,i=0,x;
	for(;i<l;++i){
		x=c[i]-'0';
		if(!ch[u][x])ch[u][x]=++xb;
		u=ch[u][x];
	}
	b[u]=1;
}
inline void bfs(){
	static int q[S];int t=0,w=1,u,i;
	for(;t<w;)for(i=0,u=q[++t];i<10;++i)if(!ch[u][i])ch[u][i]=ch[fail[u]][i];
		else q[++w]=ch[u][i],fail[q[w]]=u?ch[fail[u]][i]:0;
	for(i=1;i<=xb;++i)if(b[i])for(int&x:ch[i])x=i;
}
}A;
int f[N][S][2][2],ans,i,j,k,l,o,d,sd,ls;
char x[N],y[N],s[1005];
inline void add(int&x,int y){x+=y-mo;x+=x>>31&mo;}
int main(){
	scanf("%s%s%s",s+1,x+1,y+1);ls=strlen(s+1);d=strlen(x+1);sd=d>>1;
	for(i=1;i<=d;++i)x[i]-='0',y[i]-='0';
	for(i=1;i+sd-1<=ls;++i)A.ins(s+i,sd);A.bfs();
	f[0][0][0][0]=1;
	for(i=0;i<d;++i)for(j=0;j<=A.xb;++j)for(k=0;k<2;++k)for(l=0;l<2;++l)if(f[i][j][k][l])
		for(o=k?0:x[i+1];o<=(l?9:y[i+1]);++o)add(f[i+1][A.ch[j][o]][k|(o>x[i+1])][l|(o<y[i+1])],f[i][j][k][l]);
	for(i=1;i<=A.xb;++i)if(A.b[i])for(k=0;k<2;++k)for(l=0;l<2;++l)add(ans,f[d][i][k][l]);
	printf("%d\n",ans);
	return 0;
}