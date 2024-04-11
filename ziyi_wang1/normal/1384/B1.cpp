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
int n,m,T,k,l,a[110],b[220],f[110][220],sn;
int main(){
	read(T);
	while(T--){
		read(n);read(k);read(l);C(f,0);
		F(i,1,n)read(a[i]);
		F(i,0,k)b[i]=i;F(i,k+1,k<<1)b[i]=b[i-1]-1;
		F(i,0,(k<<1)-1)f[0][i]=1;
		F(i,1,n){
			if(f[i-1][(k<<1)-1]&&a[i]+b[0]<=l)f[i][0]=1;
			F(j,1,(k<<1)-1)if(f[i-1][j-1]&&a[i]+b[j]<=l)f[i][j]=1;
			F(j,1,(k<<1)-1)if(f[i][j-1]&&a[i]+b[j]<=l)f[i][j]=1;
			if(f[i][(k<<1)-1]&&a[i]+b[0]<=l)f[i][0]=1;
			F(j,1,(k<<1)-1)if(f[i][j-1]&&a[i]+b[j]<=l)f[i][j]=1;
		}
		sn=0;
		F(i,0,(k<<1)-1)sn|=f[n][i];
		if(sn)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}