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
const int N=(1<<18);
int n,m,fa[N+10],s[N+10],b;
ll ans;
IN find(int x){
	return fa[x]==-1?x:(fa[x]==x?x:fa[x]=find(fa[x]));
}
IN join(int x,int y){
	static int res;
	x=find(x);y=find(y);
	if(x==y)return 0;
	if(fa[x]>fa[y])swap(x,y);
	res=(fa[x]==-1?s[x]:1)+(fa[y]==-1?s[y]:1)-1;
	fa[x]=fa[y]=x;return res;
}
int main(){
	read(n);C(fa,-1);s[0]=1;
	F(i,1,n){
		read(m);s[m]++;ans-=(ll)m;
	}
	FOR(w,N-1,0){
		for(re a=w;a>0;(--a)&=w){
			b=w^a;if(s[a]&&s[b])ans+=(ll)w*join(a,b);
		}
	}
	cout<<ans;
	return 0;
}