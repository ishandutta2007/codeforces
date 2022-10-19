#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

bool prim[1200010];
vector<ll> prims;
void init(){
	for(int i=0;i<1200010;i++){
		prim[i]=true;
	}
	for(int i=2;i<1200010;i++){
		if(prim[i]){
			for(int j=2*i;j<1200010;j+=i){
				prim[j]=false;
			}
		}
	}
}

ll hoge_cnt=0;
ll hoge[800010];
ll N;

void div(ll n){
	for(int j=0;j<prims.size();j++){
		ll i=prims[j];
		if(n==1)break;
		if(i*i>n){
			if(n>N)hoge[hoge_cnt++]=i;
			break;
		}
		if(n%i == 0){
			do {
				n /= i;
			}while(n%i == 0);
			hoge[hoge_cnt++]=i;
		}
	}
}

ll xx[400010];
void rekkyo(ll x){
	/*for(int i=2*N+1;i<1200010;i++){
		if(prim[i])prims.push_back(i);
	}*/
	for(int i=-N;i<=N;i++){
		xx[i+N]=x+i;
	}
	for(int i=2;i<=2*N;i++){
		if(!prim[i])continue;
		ll y=x-N-1;
		y+=i-y%i;
		while(y<=x+N){
			do{
				xx[y-x+N]/=i;
			}while(xx[y-x+N]%i==0);
			y+=i;
		}
	}
	for(int i=2*N+1;i<1200010;i++){
		if(!prim[i])continue;
		ll y=x-N-1;
		y+=i-y%i;
		while(y<=x+N){
			hoge[hoge_cnt++]=i;
			do{
				xx[y-x+N]/=i;
			}while(xx[y-x+N]%i==0);
			y+=i;
		}
	}
	for(int i=-N;i<=N;i++){
		if(xx[i+N]!=1)hoge[hoge_cnt++]=xx[i+N];
	}
}

/*void div(ll n){
	for(ll i = 2 ; n != 1 ; i ++){
		if(!prim[i])continue;
		if(i*i>n){
			if(n>N)S.insert(n);
			break;
		}
		if(n%i == 0){
			do {
				n /= i;
			}while(n%i == 0);
			if(i>N)S.insert(i);
		}
	}
}*/

ll n;
ll a[200010];

int ret=0;

map<ll,ll> CNT;

void cnt(ll x){
	ll c=0;
	for(P p: CNT){
		if(c>=ret)break;
		if(p.fr<x)c+=p.sc*(x-p.fr);
		else {
			ll y=p.fr%x;
			c+=p.sc*min(y,x-y);
		}
	}
	ret=min((ll)ret,c);
}

int main(){
	init();
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	N=n;
	
	for(int i=0;i<n;i++){
		CNT[a[i]]++;
	}
	
	/*static ll CNT=0;
	for(int i=0;i<n;i++){
		if(a[i]==1)CNT++;
	}*/
	
	for(int i=0;i<n;i++){
		//if(a[i]==1)continue;
		if(a[i]%2==1)ret++;
	}
	
	/*if(n==200000&&a[0]!=1){
		cout<<ret<<endl;
		return 0;
	}*/
	
	for(int i=2;i<=2*n;i++){
		if(!prim[i])continue;
		cnt(i);
	}
	for(int i=2*n+1;;i++){
		if(!prim[i])continue;
		cnt(i);
		break;
	}
	
	/*if(n==200000&&a[0]!=1){
		cout<<ret<<endl;
		return 0;
	}*/
	
	//set<ll> S;
	ll x=0;
	for(int i=0;i<n;i++){
		x=max(x,a[i]);
	}
	if(x>n){
		//for(int i=-n;i<=n;i++){
			//div(x+i);
			//for(ll y: d)S.insert(y);
		//}
		rekkyo(x);
		
	/*if(n==200000&&a[0]!=1){
		cout<<ret<<endl;
		return 0;
	}*/
		for(int i=0;i<hoge_cnt;i++){
			ll y=hoge[i];
			//if(y<=n)continue;
			cnt(y);
		}
	}
	cout<<ret<<endl;
}