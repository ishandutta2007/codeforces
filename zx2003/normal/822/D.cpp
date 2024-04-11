#include<iostream>
using namespace std;
typedef long long ll;
const int N=5000010;
const ll mo=1000000007;
ll t,l,r,ans,i,f[N],p[N],xb,j,x;
bool b[N];
int main(){
	cin>>t>>l>>r;
	for(i=2;i<=r;++i){
		if(!b[i])p[++xb]=i,f[i]=(i*(i-1)>>1)%mo;
		for(j=1;j<=xb;++j){
			x=i*p[j];
			if(x>r)break;
			b[x]=1;
			f[x]=(f[i]+i*f[p[j]])%mo;
			if(i%p[j]==0)break;
		}
	}
	for(i=l,x=1;i<=r;++i){
		ans=(ans+x*f[i])%mo;
		x=x*t%mo;
	}
	cout<<ans<<endl;
	return 0;
}