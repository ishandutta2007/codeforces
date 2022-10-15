#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
I read(int &res){
	res=0;re g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
char c[101000];
int n,m,T,l,r,ans;
int main(){
	read(T);
	while(T--){
		read(n);cin>>c+1;ans=0;
		l=1;while(l<=n&&c[l]=='P')l++;
		while(l<=n&&c[l]=='A')l++;
		while(l<=n){
			r=l;
			while(r<=n&&c[r]=='P')r++;
			ans=max(ans,r-l);l=r;
			while(l<=n&&c[l]=='A')l++;
		}
		cout<<ans<<endl;
	}
	return 0;
}