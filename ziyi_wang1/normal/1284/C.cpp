#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
int n,m,Mod,fac[303000],ans;
void Plus(int &x,int y){
	x+=y;
	if(x>=Mod)x-=Mod;
}
int main(){
	cin>>n>>Mod;
	fac[0]=1;
	F(i,1,n)fac[i]=(ll)fac[i-1]*i%Mod;
	F(i,1,n)Plus(ans,(ll)(n-i+1)*(n-i+1)%Mod*fac[i]%Mod*fac[n-i]%Mod);
	cout<<ans;
	return 0;
}