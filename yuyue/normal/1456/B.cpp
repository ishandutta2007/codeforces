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
int n,a[M];
int main(){
	n=read(); 
	F(i,1,n) a[i]=read();
	F(i,1,n-1){
		int o=a[i]^a[i+1];
		if (i+1<n){
			if (o>a[i+2]){
				cout<<"1\n";
				return 0;
			}
		}
		if (i>1){
			if (o<a[i-1]){
				cout<<"1\n";
				return 0; 
			}
		}
	}
	int ans=1e9;
	F(i,1,n-1){
		int lft=0;
		DF(j,i,1){
			lft^=a[j];
			int rt=0;
			F(k,i+1,n){
				rt^=a[k];
				if (lft>rt){
					ans=min(ans,k-i-1+i-j);
				}
			}
		}
	}
	if (ans==1e9) cout<<"-1\n";
	else cout<<ans<<"\n";
	return 0;
}