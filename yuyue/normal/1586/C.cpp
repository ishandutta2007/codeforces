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
const int M=1e6+10;
vector<int> c[M]; 
int s[M],n,m;
char t[M];
int main(){
	n=read(); m=read();
	F(i,1,n){
		c[i].resize(m+2);
		scanf("%s",t+1);
		F(j,1,m){
			if (t[j]=='X'){
				if (i>1 && j<m && c[i-1][j+1]) s[j]++;
				c[i][j]=1;	
			}
		}
	}
	F(i,1,m) s[i]+=s[i-1];
	int Q=read();
	while (Q--){
		int l=read(),r=read();
		if (s[r-1]-s[l-1]) puts("NO");
		else puts("YES");
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/