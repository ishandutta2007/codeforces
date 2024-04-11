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
const int M=3e5+10;
char ch[M];
int L[M],R[M],n,ok[M];
bool dfs(int x){
	if (ok[x]!=-1) return ok[x];
	ok[x]=0;
	if (ch[x]=='>') ok[x]|=dfs(R[x]);
	if (ch[L[x]]=='<') ok[x]|=dfs(L[x]); 
	return ok[x];
}
int main(){
	int T=read();
	while (T--){
		scanf("%s",ch+1);
		n=strlen(ch+1);
		int na=0,nb=0;
		F(i,1,n){
			if (ch[i]=='A') na++;
			if (ch[i]=='B'){
				if (na){
					na--;
				}
				else nb++;
			}
		}
		nb%=2;
		cout<<nb+na<<"\n";
	}
	return 0;
}