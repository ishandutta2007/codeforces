#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int h,g;
int n,m;
int a[(1<<21)+5];
int ret[(1<<20)+5];
bool ok(int v){
	while(a[2*v]!=0||a[2*v+1]!=0){
		if(a[2*v]>a[2*v+1])v=2*v;
		else v=2*v+1;
	}
	return v>m;
}
void f(int v){
	while(a[2*v]!=0||a[2*v+1]!=0){
		if(a[2*v]>a[2*v+1]){
			a[v]=a[2*v];
			v=2*v;
		}
		else{
			a[v]=a[2*v+1];
			v=2*v+1;
		}
	}
	a[v]=0;
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&h,&g);
		n=(1<<h)-1;
		m=(1<<g)-1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=n+1;i<=2*n+1;i++){
			a[i]=0;
		}
		int r=1;
		for(int i=1;i<=n-m;i++){
			while(!ok(r))r++;
			ret[i]=r;
			f(r);
			/*cout<<i<<endl;
			for(int i=1;i<=n;i++){
				printf("%d ",a[i]);
			}cout<<endl;*/
		}
		ll sum=0;
		for(int i=1;i<=m;i++){
			sum+=a[i];
		}
		printf("%lld\n",sum);
		for(int i=1;i<=n-m;i++){
			printf("%d%c",ret[i],(i==n-m)?'\n':' ');
		}
	}
}