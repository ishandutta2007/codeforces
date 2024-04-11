#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10,inf=2e9,mod=998244353;
int n,f[M];
char s[M];
void work(){
	n=read(); scanf("%s",s+1);
	int o=0,la=1,c0=0,c1=0;
	int sg=0;
	F(i,1,n){
		if (i>1 && s[i]==s[i-1]){
			int le=i-la;
			if (le>100) le=le%34+34*5;
			sg^=f[le];
			la=i;
		}
		if (s[i]=='R') c0++;
		else c1++;
	}
	int le=n-la+1;
	if (le>100) le=le%34+34*5;
	sg^=f[le];
//	cerr<<sg<<" !!!!\n";
	if (c0+(sg>0)>c1){
		cout<<"Alice\n";
	}
	else cout<<"Bob\n";
}
int t[1010];
void init(){
	
	F(i,2,1000){
		F(j,0,1000) t[j]=0;
		F(j,0,i-2){
			t[f[j]^f[i-2-j]]=1;
		}
		while (t[f[i]]) f[i]++;
//		cerr<<f[i]<<" "<<i<<" f\n";
		if (i>100) assert(f[i]==f[i-34]);
	}
//	F(i,200,1000){
//		cerr<<i<<" "<<i%34+34<<"\n";
//		assert(f[i]==f[i%34+34*5]);
//	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	init();
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
1
12
RBRBRBRBRRBB

RBRBRBRBBBRR

*/