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
const int M=1010;
int n,m,a[M][M],b[M][M];
char ch[101010];
void work(){
	n=read(); m=read(); 
	int v[3],p[3]; ms(v,0); ms(p,0);
	F(i,0,2) p[i]=i;
	F(i,0,n-1){
		F(j,0,n-1){
			a[i][j]=read()-1;
		}
	}
	scanf("%s",ch+1);
	bool fi=0,fc=0;
	F(i,1,m){
		if (ch[i]=='R') v[p[1]]++;
		if (ch[i]=='L') v[p[1]]--;
		if (ch[i]=='U') v[p[0]]--;
		if (ch[i]=='D') v[p[0]]++;
		if (ch[i]=='I') swap(p[1],p[2]),fi^=1;
		if (ch[i]=='C') swap(p[0],p[2]),fc^=1;
	}
	F(i,0,n-1){
		F(j,0,n-1){
			int t[3];
			t[0]=i,t[1]=j,t[2]=a[i][j];
			t[0]=((t[0]+v[0])%n+n)%n;
			t[1]=((t[1]+v[1])%n+n)%n;
			t[2]=((t[2]+v[2])%n+n)%n;
//			cout<<i<<" "<<j<<" --> "<<x<<" "<<y<<"\n"; 
			b[t[p[0]]][t[p[1]]]=t[p[2]];
		}
	}
	F(i,0,n-1){
		F(j,0,n-1){
			cout<<b[i][j]+1<<" ";
		}
		cout<<"\n"; 
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