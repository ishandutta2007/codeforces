#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
int n;
map<LL,int> mp;
void solve(){
	n=read(); 
	bool fl=0; mp.clear();
	F(i,1,n){
		int x=read();
		if (!mp[x]) mp[x]=1;
		else fl=1;
	}
	if (fl) puts("YES");
	else puts("NO");
}
int main(){
	int T=read(); srand(time(0));
	while (T--){
		 solve();
	}
    return 0;
}