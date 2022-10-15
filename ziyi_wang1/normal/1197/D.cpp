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
const ll INF=1e18+9;
ll n,m,k,ans,sum,a[303000],s[303000],maxi[303000];
IN max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	read(n);read(m);read(k);
	F(i,1,n){
		read(a[i]);
	}
	ans=0;
	F(j,0,m-1){
		s[0]=0;
		F(i,1,n){
			s[i]=s[i-1]+a[i];
			if(i%m==j)s[i]-=k;
		}	
		maxi[n+1]=-INF;
		FOR(i,n,1){
			maxi[i]=max(maxi[i+1],s[i]);
		}
		sum=-INF;
		for(re i=j;i<=n;i+=m){
			if(!i)continue;
			sum=max(sum,maxi[i]-s[i-1]);
		}
		ans=max(ans,sum);
	}
	cout<<ans;
    return 0;
}