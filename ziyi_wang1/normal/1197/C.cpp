#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
ll n,m,a[303000],b[303000];
ll ans=0;
int main(){
	cin>>n>>m;
	F(i,1,n){
		cin>>a[i];
	}
	F(i,1,n-1){
		b[i]=a[i+1]-a[i];
	}
	sort(b+1,b+n);
	F(i,1,n-m){
		ans+=1ll*b[i];
	}
	cout<<ans;
    return 0;
}