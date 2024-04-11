#include <cstdio>
const int N=2e5+10,PW=20;
int n,m,q,a[N],num[N],st[PW][N];
namespace basic{
	int res;char cdc;
	template<typename T>T max(T x,T y){return x>y?x:y;}
	template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
}using basic::max;using basic::swp;using basic::read;
inline int query(int l,int r){
	if(l>r)swp(l,r);int w=num[r-l+1];
	return max(st[w][l],st[w][r-(1<<w)+1]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i)if((1<<((num[i]=num[i-1])+1))==i)++num[i];
	for(int i=1;i<=m;++i)a[i]=read(),st[0][i]=a[i];
	for(int i=1;i<PW;++i)for(int j=1;j+(1<<i)-1<=m;++j)st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	q=read();
	for(int k,sx,sy,tx,ty,i=1;i<=q;++i){
		sx=read(),sy=read(),tx=read(),ty=read(),k=read();
		sx+=(n-sx)/k*k,tx+=(n-tx)/k*k;if(sx!=tx||(sy-ty)%k!=0){puts("NO");continue;}
		puts(query(sy,ty)<tx?"YES":"NO");
	}
	return 0;
}