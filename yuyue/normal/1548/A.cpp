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
const int M=6e5+10;
int n,m;
set<int> s[M];
int ans=0;
void add(int x){
	if (-(*s[x].begin())<=x) ans++;
}
void del(int x){
	if (-(*s[x].begin())<=x) ans--;
}
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		s[x].insert(-y);
		s[y].insert(-x);
	}
	F(i,1,n){
		s[i].insert(0);
		add(i);
	}
	int Q=read();
	F(i,1,Q){
		int op=read();
		if (op<=2){
			
			int x=read(),y=read();
			if (op==1){
				del(x); del(y);
				s[x].insert(-y);
				s[y].insert(-x);
				add(x); add(y);
			}
			else{
				del(x); del(y);
				s[x].erase(-y);
				s[y].erase(-x);
				add(x); add(y);
			}
		}
		else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/