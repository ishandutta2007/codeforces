#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
} 
const int M=2e5+10;
int f[M];
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
struct node{
	int x,y,z;
}a[M];
bool cmp(node A,node B){
	return A.z<B.z;
}
int n,m,k;
void work(){
	n=read(); m=read(); k=read();
	int mi=2e9;
	F(i,1,m){
		a[i].x=read();
		a[i].y=read();
		a[i].z=read();
		mi=min(abs(a[i].z-k),mi);
	}
	sort(a+1,a+m+1,cmp);
	int cnt=0;
	LL ans=0;
	F(i,1,n) f[i]=i; 
	F(i,1,m){
		int u=Fd(a[i].x),v=Fd(a[i].y);
		if (u==v) continue;
		f[u]=v;
		cnt++;
		ans+=max(0,a[i].z-k);
		if (cnt==n-1){
			if (ans==0) cout<<mi<<"\n";
			else cout<<ans<<"\n";
			return ;
		}
	}
}
int main(){
	int T=read();
	while (T--) work(); 
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/