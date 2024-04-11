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
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
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
char c[1010000];
int n,m,now,ans,las;
int main(){
	read(n);
	cin>>c+1;
	las=0;
	F(i,1,n){
		if(c[i]=='(')now++;
		else now--;
		if(!now&&c[i]=='(')ans+=i-las;
		if(!now)las=i;
	}
	if(now)cout<<"-1";
	else cout<<ans;
	return 0;
}