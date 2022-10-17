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
		n=read();
		scanf("%s",ch);
		F(i,0,n-1) ok[i]=-1;
		bool sl=0,sr=0;
		F(i,0,n-1){
			L[i]=(i-1+n)%n;
			R[i]=(i+1)%n;
			if (ch[i]=='-') ok[i]=ok[R[i]]=1;
			if (ch[i]=='>') sl=1;
			if (ch[i]=='<') sr=1;
		}
		if (!sl || !sr){
			cout<<n<<"\n";
			continue;
		}
		int ans=0;
		F(i,0,n-1) if (ok[i]==1) ans++;
		cout<<ans<<"\n"; 
	}
	return 0;
}