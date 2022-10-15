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
char a[1010],b[1010],c[1010];
int T,n,m;
int main(){
	read(T);
	while(T--){
		cin>>a+1>>b+1>>c+1;
		n=strlen(a+1);m=1;
		F(i,1,n){
			if(a[i]==c[i]||b[i]==c[i])continue;
			m=0;break;
		}
		if(m)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}