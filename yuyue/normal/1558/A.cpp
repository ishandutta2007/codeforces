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

int main(){
	int T=read();
	while (T--){
		int a=read(),b=read();
		vector<int> ans;
		F(i,0,a+b){
			bool fl=0;
			F(o,0,1){
				int c=(a+b+o)/2;
				int del=c+i-a-b;
				if ((del-b)%2) continue;
				int x=(del+b)/2,y=(b-del)/2;
				if (x<=c && x>=0 && y>=0 && y<=a+b-c){
					fl=1;
				}
			}
			if (fl) ans.pb(i);
		}
		cout<<ans.size()<<"\n";
		F(i,0,SZ(ans)) cout<<ans[i]<<" ";
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