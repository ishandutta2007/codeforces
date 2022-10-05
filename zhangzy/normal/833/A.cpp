#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;ll a,b,c;

ll doit(ll x){
	ll l=1,r=1000001,mid,tem,turn=0;
	while (l<=r){
		mid=(l+r)>>1;
		tem=mid*mid*mid;
		if (tem>=x){
			turn=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return turn;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d%I64d",&a,&b);
		c=doit(a*b);
		if (c*c*c==a*b&&a%c==0&&b%c==0){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}