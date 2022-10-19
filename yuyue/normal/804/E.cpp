#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int a[1111],n; 
void ds(int x,int y){
	cout<<x<<" "<<y<<"\n";
	swap(a[x],a[y]);
}
int fl;
void inner(int *p){
	if (!fl) ds(p[0],p[1]);
	else ds(p[0],n+1),ds(p[0],p[1]),ds(p[1],n+1);
	if (!fl) ds(p[2],p[3]);
	else ds(p[2],n+1),ds(p[2],p[3]),ds(p[3],n+1);
	ds(p[0],p[2]);
	ds(p[1],p[3]);
	ds(p[0],p[3]);
	ds(p[1],p[2]);
}
void small(int *p,int *q){
	ds(p[0],q[1]);
	ds(p[1],q[0]);
	ds(p[0],q[0]);
	ds(p[1],q[1]);
}
void inter(int *p,int *q){
	small(p,q); small(p+2,q+2); small(p,q+2); small(p+2,q); 
}
int p[1111];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	F(i,1,n) a[i]=i,p[i]=i;
	fl=n%4;
	if (fl>1){
		puts("NO");
		return 0;
	}
	puts("YES");
	n-=fl;
	for (int i=1;i<=n;i+=4){
		inner(p+i);
	}
	for (int i=1;i<=n;i+=4){
		for (int j=i+4;j<=n;j+=4){
			inter(p+i,p+j);
		}
	}
//	F(i,1,n+fl) cout<<a[i]<<" ";
//	cout<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/