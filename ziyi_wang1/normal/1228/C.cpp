#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline ll
typedef long long ll;
I read(ll &res){
    re g=1;register char ch=getchar();res=0;
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
const ll E=1e9+7;
ll n,m,lim,x,s[100],tot,ans;
IN Pow(ll bas,ll y){
	re res=1ll;
	while(y){
		if(y&1ll)res=(res*bas)%E;
		bas=(bas*bas)%E;
		y>>=1;
	}
	return res;
}
const ll INF=1e18+7;
int main(){
	read(x);read(n);
	m=2;lim=sqrt(x);
	while(x){
		if(m>lim){
			s[++tot]=x;
			break;	
		}
		if(x%m==0){
			s[++tot]=m;
			while(x%m==0)x/=m;
		}
		m++;
	}	
	//system("pause");
	ans=1;
	F(i,1,tot){
		m=s[i];
		if(m==1)continue;
		while(m<=n){
			ans=(ans*Pow(s[i],(n/m)))%E;
			if((INF/m)<s[i])break;
			m*=s[i];
		}
	}
	cout<<ans;
    return 0;
}