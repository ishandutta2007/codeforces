#include<bits/stdc++.h>
#define xxx 10000000
#define ll long long
using namespace std;
int n,cnt[10001000];
ll tot,a,b,ans=1;
bitset<10001000>np;

void doit(ll x,ll y){
	if (y==0) return;
	ll l=1,r=x*y,mid,turn,t,z;
	while (l<=r){
		mid=(l+r)>>1;
		z=mid;
		t=0;
		for (;z>0;){
			t+=z/x;
			z/=x;
		}
		if (t>=y){
			r=(turn=mid)-1;
		}else{
			l=mid+1;
		}
	}
	ans=max(ans,turn);
}

int main(){
	int x;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		cnt[x]++;
	}
	for (int i=2;i<=xxx;i++){
		cnt[i]+=cnt[i-1];
	}
	
	np.reset();
	np[1]=1;
	for (int i=2;i<=xxx;i++){
		if (!np[i]){
			for (int j=i+i;j<=xxx;j+=i){
				np[j]=1;
			}
		}
	}
	
	for (int i=2;i<=xxx;i++){
		if (np[i]) continue;
		//printf("%d ",i);
		tot=0;
		for (a=i;a<=xxx;a*=i){
			b=0;
			for (int j=a;j<=xxx;j+=a){
				b++;
				tot+=b*(cnt[min(j+a-1,(ll)xxx)]-cnt[j-1]);
			}
		}
		//cout<<tot<<endl;
		doit(i,tot);
	}
	cout<<ans;
}