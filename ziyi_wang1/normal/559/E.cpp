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
const int INF=1e9+7;
struct P{
	int x,y,a;
	friend bool operator < (P a,P b){return a.a<b.a;}
}p[110];
vector<int>v;
int n,m,f[110][330],g[330],L,R,P,X,Y;
I get(int &x){x=lower_bound(v.begin(),v.end(),x)-v.begin();}
int main(){
	read(n);v.emplace_back(-INF);
	F(i,1,n){
		read(p[i].a);read(m);p[i].x=p[i].a-m;p[i].y=p[i].a+m;
		v.emplace_back(p[i].a);v.emplace_back(p[i].x);v.emplace_back(p[i].y);
	}
	sort(p+1,p+1+n);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());m=v.size()-1;
	F(i,1,n)get(p[i].a),get(p[i].x),get(p[i].y);
	F(i,1,n){
		F(j,1,m)f[i][j]=f[i-1][j];
		X=p[i].x;Y=p[i].y;P=p[i].a;
		R=P;C(g,0);
		g[R]=f[i-1][X]+v[R]-v[X];
		FOR(j,i-1,1){
			R=max(R,p[j].y);
			g[R]=max(g[R],f[j-1][X]+v[R]-v[X]);
		}
		FOR(j,m,X)f[i][j]=max(f[i][j],g[j]),g[j-1]=max(g[j-1],g[j]-v[j]+v[j-1]);
		F(j,P,Y)f[i][j]=max(f[i][j],f[i-1][P]+v[j]-v[P]);
		F(j,1,m)f[i][j]=max(f[i][j],f[i][j-1]);
	}
	cout<<f[n][m];
	return 0;
}