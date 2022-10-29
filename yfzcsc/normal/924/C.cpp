#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
int X,a[maxn],sta[maxn],tp,n;
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int nw;
		scanf("%d",&nw);
		if(nw==X){
			X++;
		} else if(nw<X){
			ans+=X-nw-1;
			sta[++tp]=i;
		} else {
			int rest=nw-X;
			while(rest){
				int u=sta[tp--];
				ans+=i-u;
				rest--;
			}
			X=nw+1;
		}
	}
	printf("%lld",ans);
}