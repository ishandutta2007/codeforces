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
const int M=3333; 
int b[M][M],a[M][M];
int main(){
	int T=read();
	while (T--){
		int n=read(),m=read();
		F(i,1,n) F(j,1,m) a[i][j]=read();
		bool flag=0; 
		F(i,1,n){
			F(j,1,m){
				int num=4-(i==1)-(i==n)-(j==1)-(j==m); 
				if (num<a[i][j]) {
					puts("NO");
					flag=1;
					break;
				}
				b[i][j]=num;
			}
			if (flag) break;
		}
		if (!flag){
			puts("YES");
			F(i,1,n){
				F(j,1,m) cout<<b[i][j]<<" ";
				cout<<"\n";
			}
		}
	}
	return 0;
}