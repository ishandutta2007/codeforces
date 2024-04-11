#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline ll
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
const ll Mod=1e9+7;
ll n,m,ans,v[101000],twice[101000],a[101000],t[101000],prime[101000],tot,mu[101000];
int main(){
	read(n);
	F(i,1,n)read(a[i]);
	F(i,1,n){
		F(j,1,sqrt(a[i])){
			if(a[i]%j==0){
				t[j]++;
				if(j*j!=a[i])t[a[i]/j]++;
			}
		} 
	}
	tot=0;mu[1]=1;twice[0]=1;
	F(i,1,100000)twice[i]=twice[i-1]*2ll%Mod;
	F(i,2,100000){
		if(!v[i])prime[++tot]=i,mu[i]=-1;
		F(j,1,tot){
			if(i*prime[j]>100000)break;
			v[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}
			else mu[i*prime[j]]=-mu[i];
		}
	}
	F(i,1,100000)ans=(ans+(ll)(twice[t[i]]-1)*mu[i]+Mod)%Mod;
	printf("%lld",ans);
	return 0;
}