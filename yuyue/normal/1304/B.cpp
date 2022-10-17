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
const int M=110;
char ch[M][M];
vector<int> r,s,t;
bool used[M];
int n,m;
int main(){
	n=read(); m=read();
		F(i,1,n){
			scanf("%s",ch[i]+1);
		}
		F(i,1,n){
			if (used[i]) continue;
			F(j,i+1,n){
				if (used[j]) continue;
				bool sm=1;
				F(k,1,m){
					if (ch[i][k]!=ch[j][m-k+1]) {
						sm=0;
						break;
					}
				}
				if (sm) {
					r.pb(i);
					s.pb(j);
					used[i]=used[j]=1;
					break;
				}
			}
		}
		F(i,1,n){
			if (used[i]) continue;
			bool sm=1;
			F(j,1,m){
				if (ch[i][j]!=ch[i][m-j+1]) {
					sm=0;
					break;
				}
			}
			if (sm) t.pb(i);
		}
		cout<<m*(SZ(r)+1+min(1,SZ(t)+1)+SZ(s)+1)<<"\n";
		F(i,0,SZ(r)) {
			cout<<(ch[r[i]]+1);
		}
		if (SZ(t)+1>0){
			cout<<(ch[t[0]]+1);
		}
		DF(i,SZ(s),0) cout<<(ch[s[i]]+1);
	
	return 0;
}