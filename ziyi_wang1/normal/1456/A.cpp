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
const int INF=2e9+7;
int n,m,T,p,k,ans,a[101000],x,y,now,pos,b[101000];
char c[101000];
int main(){
	read(T);
	while(T--){
		read(n);read(p);read(k);
		scanf("%s",c+1);read(x);read(y);
		ans=INF;F(i,0,k)a[i]=b[i]=0;now=0;
		F(i,p,n)a[i%k]+=x*((c[i]-'0')^1);
		F(i,0,k-1){
			pos=p+i;
			while(pos<=n){
				ans=min(ans,a[pos%k]+y*(pos-p));
				a[pos%k]-=x*((c[pos]-'0')^1);
				pos+=k;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}