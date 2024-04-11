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
int t[3],o[3];
#define a o[0]
#define b o[1]
#define c o[2]
int c1(){
	int ans=0;
	if (a) ans++,a--;
	if (b) ans++,b--;
	if (c) ans++,c--;
	if (a&&b) ans++,a--,b--;
	if (a&&c) ans++,a--,c--;
	if (c&&b) ans++,c--,b--;
	if (a&&b&&c) ans++,a--,b--,c--;
	return ans;
}
int main(){
//	freopen("in.txt","r",stdin);
	int T=read();
	while (T--){
		F(i,0,2)
		t[i]=read(); 
		sort(t+1,t+3);
		int ans=0;
		do{
			F(i,0,2) o[i]=t[i];
			ans=max(ans,c1());
		}while (next_permutation(t,t+3));
		cout<<ans<<"\n";
	}
	return 0;
}