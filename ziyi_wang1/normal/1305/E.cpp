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
const int INF=1e5;
int n,m,now,num,inf,t,l,r,len,a[5050],pos;
IN calc(int x){
	if(x&1)return (x-1)*(x-1)/4;
	else return x*(x-2)/4;
}
int main(){
	read(n);read(m);
	inf=1e9;t=n;
	F(i,1,n)a[i]=i;
	now=calc(n);
	//cout<<now<<endl;
	if(now<m){
		cout<<"-1";return 0;
	}
	while(now>m){
		r=t-1;l=1;len=t-1;pos=t;
		while(now>m&&len>1){
			len--;pos++;if(len&1)now--;
		}
		if(now==m){
			a[t]=pos;break;
		}
		else a[t]=inf,inf-=INF,t--;
	}
	F(i,1,n)cout<<a[i]<<" ";
	return 0;
}