#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
ll n,m,l,r,ans;
int main(){
	cin>>n>>l>>r;
	ans=(n-l);m=1;
	F(i,1,l){
		ans+=m;
		m<<=1;
	}
	printf("%I64d ",ans);
	ans=0;m=1;
	F(i,1,r){
		ans+=m;
		m<<=1;
	}
	m>>=1;
	ans+=(m*(n-r));
	printf("%I64d",ans);
    return 0;
}