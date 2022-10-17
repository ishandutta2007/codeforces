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
int n,m,sn,a[202000],b[1010],ans;
IN calc(int x,int y){
	re res=x-y;if(res<0)res=-res;return res;
}
int main(){
	read(n);read(m);
	if(n>m){
		cout<<"0";return 0;
	}
	F(i,1,n)read(a[i]);
	ans=1;
	F(i,1,n-1){
		F(j,i+1,n){
			ans=(ll)ans*calc(a[i],a[j])%m;
		}
	}
	cout<<ans;
	/*
	F(i,1,n){
		read(a[i]);a[i]%=m;
		b[a[i]]++;
	}
	sn=1;
	F(i,0,m-1)if(b[i]>1)sn=0;
	if(!sn){
		cout<<"0";return 0;
	}
	ans=1;
	
	cout<<ans;*/
	return 0;
}