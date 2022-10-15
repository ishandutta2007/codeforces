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
int n,m,T,a[110],sn;
int main(){
	read(T);
	while(T--){
		read(n);sn=0;
		F(i,1,n)read(a[i]);
		if(n==1&&a[1]&1)cout<<"-1"<<endl;
		else{
			F(i,1,n){
				if(!(a[i]&1)){
					sn=1;cout<<"1"<<endl<<i<<endl;
					break;
				}
			}
			if(!sn)cout<<"2"<<endl<<"1 2"<<endl;
		}
	}
	return 0;
}