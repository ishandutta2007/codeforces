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
const int M=1e5+10;
int a[M];
int main(){
	int T=read();
	while (T--){
		int n=read();
		set<int> s;
		F(i,1,n)	s.insert(i);
		bool bad=0;
		int now=0;
		F(i,1,n){
			int x=read();
			if (bad) continue;
			if (x<now) {
				bad=1;
				continue;
			}
			else if (x==now){
				if (*s.begin()>x) {
					bad=1;
					continue;
				}
				a[i]=*s.begin();
				s.erase(s.begin());
			}
			else {
				a[i]=x;
				s.erase(x);
			}
			now=x;
		}
		if (bad) {
			puts("-1");
			continue;
		}
		F(i,1,n) cout<<a[i]<<" "; cout<<"\n";
	}
    return 0;
}