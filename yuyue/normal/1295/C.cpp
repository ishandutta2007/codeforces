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
const int M=1e5+10;
char s[M],t[M];
vector<int> v[30];
int main(){
	int T=read();
	while (T--){
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		F(i,0,25) v[i].clear();
		F(i,1,n){
			int o=s[i]-'a';
			v[o].pb(i);
		}
		int pos=0;
		bool f=0;
		int ans=0;
		F(i,1,m){
			int o=t[i]-'a';
			if (!v[o].size()) {
				f=1;
				puts("-1");
				break;
			}
			if (v[o][SZ(v[o])]<pos){
				pos=0;
				i--;
				ans++;
			}
			else {
				pos=*lower_bound(v[o].begin(),v[o].end(),pos)+1;
			}
		}
		if (!f) cout<<ans+(pos!=0)<<"\n"; 
	}
	return 0;
}