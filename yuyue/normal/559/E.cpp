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
const int M=500;
struct node{
	int p,l;
}a[M];
bool cmp(node A,node B){
	return A.p<B.p;
}
int dp[M][M][2],n;
int main(){
	n=read(); 
	F(i,1,n) a[i]=node{read(),read()};
	sort(a+1,a+n+1,cmp);
	a[0]=node{-(1<<29),0}; int ans=0;
	F(i,0,n){
		F(j,0,i){
			F(t,0,1){
				if (ans<dp[i][j][t]) ans=dp[i][j][t];
				int L=a[j].p+t*a[j].l;
				int R=-1,ff,op;
				F(k,i+1,n){
					F(o,0,1){
						int tmp=a[k].p+o*a[k].l;
						if (tmp>R) R=tmp,ff=k,op=o;
						dp[k][ff][op]=max(dp[k][ff][op],dp[i][j][t]+min(tmp-L,a[k].l)+R-tmp); 
					}
				}
			}
		}
	} 
	cout<<ans<<"\n";
	return 0;
}