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
int n;
int a[M],pre[2][M],ct[2];
void work(){
	n=read(); ct[0]=ct[1]=0;
	F(i,1,n) a[i]=read()&1,ct[a[i]]++,pre[a[i]][ct[a[i]]]=ct[a[i]^1];
	if (ct[1]!=n/2 && ct[0]!=n/2){
		puts("-1");
		return ;
	}
	LL ans=0;
	if (n&1){
		int fi=(ct[1]>ct[0]);
		int num[2]={0,0};
		F(i,1,n){
			num[fi]++;
			ans+=max(0,pre[fi][num[fi]]-num[fi^1]);
			fi^=1;
		}
	}
	else{
		ans=1e18;
		F(fi,0,1){
			LL tmp=0;
			int num[2]={0,0};
			F(i,1,n){
				num[fi]++;
				tmp+=max(0,pre[fi][num[fi]]-num[fi^1]);
				fi^=1;
			}
			ans=min(ans,tmp);
		}
	}
	cout<<ans<<"\n";
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