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
const int INF=1e9;
int T,n,m,a[101000],l,r,nl,nr;
IN Abs(int x){
	return x<0?-x:x;
}
IN ck(int x,int sn){
	l=0;r=INF;
	F(i,1,n){
		if(a[i]==-1||(a[i-1]!=-1&&a[i+1]!=-1))continue;
		nl=max(0,a[i]-x);nr=min(a[i]+x,INF);
		if(nl>r||nr<l||l>r)return 0;
		l=max(l,nl);r=min(r,nr);
	}
	if(sn==1)cout<<l<<endl;
	//cout<<x<<" "<<l<<" "<<r<<endl;
	return 1;
}
I divided(int x,int y){
	if(x==y){
		cout<<x<<" ";
		ck(x,1);return;
	}
	re mid=(x+y)>>1;
	if(ck(mid,0))y=mid;
	else x=mid+1;
	divided(x,y);
}
int main(){
	read(T);
	while(T--){
		read(n);
		F(i,1,n)read(a[i]);m=0;
		F(i,1,n-1)if(a[i]!=-1&&a[i+1]!=-1)m=max(m,Abs(a[i]-a[i+1]));
		divided(m,INF);
		F(i,1,n)a[i]=0;
	}
	return 0;
}