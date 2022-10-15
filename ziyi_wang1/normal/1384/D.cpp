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
int n,m,T,a[101000],cnt;
IN lbt(int x){return x&(-x);}
int main(){
	read(T);
	while(T--){
		read(n);m=cnt=0;
		F(i,1,n)read(a[i]),m^=a[i];
		if(!m){
			cout<<"DRAW"<<endl;
			continue;
		}
		while(lbt(m)^m)m-=lbt(m);
//		cout<<m<<endl;
		F(i,1,n)if((a[i]&m))cnt++;
		if(cnt==1){
			cout<<"WIN"<<endl;
			continue;
		}
		if(n&1){
			if((cnt%4)==1)cout<<"WIN"<<endl;
			else cout<<"LOSE"<<endl;
		}
		else cout<<"WIN"<<endl;
	}
	return 0;
}