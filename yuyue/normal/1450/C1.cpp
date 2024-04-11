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
const int M=500+10;
int n,ct[50];
char ch[M][M];
void work(){
	n=read(); ms(ct,0);
	F(i,1,n){
		scanf("%s",ch[i]+1);
		F(j,1,n){
			if (ch[i][j]!='.') ct[(i-j+n)%3]++;
		}
	}
	int mip=0;
	F(i,1,2) if (ct[i]<ct[mip]) mip=i;
	F(i,1,n){
		F(j,1,n){
			int id=i-j+n;
			if (id%3!=mip || ch[i][j]=='.'){
				cout<<ch[i][j];
				continue;
			}
			id=(id-mip)/3;
			cout<<"O";
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