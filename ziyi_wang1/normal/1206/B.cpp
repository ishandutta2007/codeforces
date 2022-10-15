#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
ll ans;
int n,m,a[101000],sn;
int main(){
	cin>>n;sn=0;ans=0ll;
	F(i,1,n){
		cin>>a[i];
		if(a[i]>=1)ans+=1ll*(a[i]-1),a[i]=1;
		else if(!a[i])ans++,sn=2;
		else if(a[i]<=-1)ans+=1ll*(-a[i]-1),a[i]=-1,sn^=1;
	}
	if(sn>>1||(!sn))cout<<ans;
	else cout<<ans+2ll;
    return 0;
}