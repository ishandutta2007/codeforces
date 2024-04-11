#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll a,b,f[520],g;
int c[520];

ll all1(ll x){
	if (x<=1) return 0;
	return f[x]+all1(x-1);
}

int cc[233];
bool ok(int l){
	for (int i=1;i<=l;i++){
		cc[i]=c[i+g-l];
	}
	for (int i=g-l;i>0;i--){
		if (cc[(i-1)%l+1]<c[i]){
			return 1;
		}
		if (cc[(i-1)%l+1]>c[i]){
			return 0;
		}
	}
	return 1;
}

ll q[233];
ll doit(ll x){
	if (x<1) return 0;
	g=0;
	while (x>0){
		c[++g]=x&1;
		x>>=1;
	}
	ll t=all1(g-1),d=0,e;
	//cout<<g-1<<' '<<t<<endl;
	for (int i=g;i>=max(g/2,(ll)2);i--){
		d=d*2+c[i];
		e=(ll)1<<(g-i);
		q[g-i+1]=0;
		if (g%(g-i+1)==0){
			q[g-i+1]=(d-e+(ok(g-i+1)?1:0));
			for (int j=g-i;j>0;j--){
				if ((g-i+1)%j==0)
				q[g-i+1]-=q[j];
			}
			//printf(" %d %lld %lld %d %lld\n",i,d,e,ok(g-i+1),q[g-i+1]);
			t+=q[g-i+1];
		}
	}
	//cout<<' '<<t<<endl;
	return t;
}

int main(){
	f[1]=0;
	for (int i=2;i<=60;i++){
		f[i]=0;
		for (int j=1;j<=i/2;j++){
			if (i%j==0){
				f[i]+=((ll)1<<(j-1))-f[j];
			}
		}
		//cout<<i<<' '<<f[i]<<endl;
	}
	cin>>a>>b;
	ll ans=doit(b)-doit(a-1);
	cout<<ans;
}