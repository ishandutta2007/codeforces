#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
#define B155 bitset<155>
const int INF=1e9+1546462;
struct E{
	int x,y,w;
	friend bool operator < (E a,E b){return a.w<b.w;}
}e[155];
B155 A[155],B[155],C[155],D[155];
int n,m,dis[155][155],ans,X,Y,W;
B155 mul(B155 *x,B155 *y){
	B155 res[155];
	F(i,1,n)res[i].reset();
	F(i,1,n){
		F(j,1,n)if(x[i][j])res[i]|=y[j];
	}
	F(i,1,n)x[i]=res[i];
}
I Pow(int x){
	F(i,1,n)C[i]=B[i],D[i].reset(),D[i][i]=1;
	while(x){
		if(x&1)mul(D,C);
		mul(C,C);
		x>>=1;
	}
}
int main(){
	read(n);read(m);F(i,1,n)F(j,1,n)dis[i][j]=INF;ans=INF;
	F(i,1,n)dis[i][i]=0,A[i][i]=1;
	F(i,1,m)read(e[i].x),read(e[i].y),read(e[i].w);
	sort(e+1,e+1+m);
	e[0].w=0;
	F(i,1,m){
		X=e[i].x;Y=e[i].y;W=e[i].w;
		Pow(e[i].w-e[i-1].w);
		mul(A,D);
		F(j,1,n){
			F(k,1,n)dis[j][k]=min(dis[j][k],dis[j][X]+1+dis[Y][k]);
		}
		F(j,1,n-1)if(A[1][j])ans=min(ans,W+dis[j][n]);
		B[X][Y]=1;
	}
	if(ans==INF)cout<<"Impossible";
	else cout<<ans;
	return 0;
}