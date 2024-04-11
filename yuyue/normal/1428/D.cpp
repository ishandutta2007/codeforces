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
int n,a[M],mt[M];
#define pii pair<int,int>
#define mp make_pair
int s[M];
int main(){
	n=read();
	F(i,1,n){
		a[i]=read();
	}
	int tp=0;
	int pos=n;
	vector<pii> ans; 
	DF(i,n,1){
		if (a[i]==1) s[++tp]=i;
		if (a[i]==2){
			if (!tp){
				cout<<"-1\n";
				return 0;
			}
			mt[i]=s[tp--]; 
			ans.pb(mp(pos,i)); 
			ans.pb(mp(pos,mt[i]));
			pos--;
			a[i]=1;
			a[mt[i]]=0; 
		}
	}
	while (tp){
		ans.pb(mp(pos,s[tp]));
		tp--;
		pos--;
	}
	tp=0;
	DF(i,n,1){
		if (a[i]==1) s[++tp]=i;
		if (a[i]==3){
			if (!tp || !pos){
				cout<<"-1\n";
				return 0;
			}
			mt[i]=s[tp--];
			ans.pb(mp(pos,i)); 
			ans.pb(mp(pos,mt[i]));
			pos--;
			s[++tp]=i;
		}
	}
	cout<<SZ(ans)+1<<'\n';
	F(i,0,SZ(ans)) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}