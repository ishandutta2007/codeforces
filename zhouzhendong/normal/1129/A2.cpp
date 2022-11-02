#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=20005;
int n,m;
vector <int> p[N];
int nxt(int x){
	return x==n?1:x+1;
}
int ans[N];
int main(){
	n=read(),m=read();
	For(i,1,m){
		int a=read(),b=read();
		b-=a;
		if (b<0)
			b+=n;
		p[a].pb(b);
	}
	memset(ans,-1,sizeof ans);
	For(i,1,n)
		sort(p[i].begin(),p[i].end());
	For(i,1,n){
		if (!p[i].empty()){
			int Mx=0,t=0;
			for (int j=i;!t||j!=i;j=nxt(j)){
				if (p[j].size()>0){
					Mx=max(Mx,t+(int)(p[j].size()-1)*n+p[j][0]);
//					outval(j);
//					outval(Mx);
				}
				t++;
			}
			ans[i]=Mx;
		}
	}
	Fod(i,n,1)
		if (!~ans[i]&&~ans[nxt(i)])
			ans[i]=ans[nxt(i)]+1;
	Fod(i,n,1)
		if (!~ans[i]&&~ans[nxt(i)])
			ans[i]=ans[nxt(i)]+1;
	For(i,1,n)
		printf("%d ",ans[i]);
	return 0;
}