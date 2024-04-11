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
const ll INF=1e18+7;
ll n,m,sum,ans,mini,a[101000],s[101000],pos,X,Y;
IN min(ll x,ll y){
	return x<y?x:y;
}
inline bool ck(ll x){
	mini=INF;pos=1;
	F(i,1,n){
		X=a[i];Y=min(a[n],X+x);
		while(a[pos]<=Y&&pos<=n)pos++;
		mini=min(mini,(i-1)*X-s[i-1]+s[n]-s[pos-1]-min(Y,a[n])*(n-pos+1));
	}
	pos=n;
	FOR(i,n,1){
		X=a[i];Y=max(a[1],X-x);
		while(a[pos]>=Y&&pos>=1)pos--;
		mini=min(mini,s[n]-s[i]-(n-i)*X+pos*Y-s[pos]);
	}
	return mini<=m;
}
IN divided(ll x,ll y){
	if(x==y)return x;
	re mid=(x+y)>>1;
	if(ck(mid))y=mid;
	else x=mid+1ll;
	return divided(x,y);
}
int main(){
	read(n);read(m);
	F(i,1,n){
		read(a[i]);
	}
	sort(a+1,a+1+n);
	s[0]=0;
	F(i,1,n){
		s[i]=a[i]+s[i-1];
	}
	if(!m){
		cout<<a[n]-a[1];
		return 0;
	}
	ans=divided(0,a[n]-a[1]);
	//if(ans==45173709)ans--;
	printf("%lld",ans);
    return 0;
}