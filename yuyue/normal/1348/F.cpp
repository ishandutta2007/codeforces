#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define oo(x) fixed<<setprecision(x)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
#define pii pair<int,int> 
vector<pii> v[M];
int n,pos[M],ans[M],l[M],r[M];
priority_queue<pii ,vector<pii >, greater<pii > > qi;
int main(){
	n=read(); 
	F(i,1,n){
		int x=read(),y=read();
		l[i]=x; r[i]=y;
		v[x].pb({y,i}); 
	}
	int ca=0,cb=0;
	stack<pii > s;
	F(i,1,n){
		F(j,0,SZ(v[i])) qi.push(v[i][j]);
		int o=qi.top().second; qi.pop();
		while (s.size() && r[s.top().second]<i) s.pop();
		if (s.size() && s.top().first>=l[o]) {
			ca=o; cb=s.top().second;
		}  
		ans[o]=i; s.push({i,o});
	}
	if (!ca){
		puts("YES");
		F(i,1,n) cout<<ans[i]<<" "; cout<<"\n";
	} 
	else{
		puts("NO");
		F(i,1,n) cout<<ans[i]<<" "; cout<<"\n";
		swap(ans[ca],ans[cb]); 
		F(i,1,n)  cout<<ans[i]<<" "; cout<<"\n";
	}
    return 0;
}