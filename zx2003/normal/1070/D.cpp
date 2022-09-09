#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define per(i,a,b) for (int i=a;i>=b;i--)
#define maxn 200005
int n,k,a[maxn];

int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	int remain=0;ll res=0;
	rep(i,1,n){
		int v=(remain+k-1)/k;
		res+=v;remain=remain+a[i]-v*k;
		if (remain<0)remain=0;
	}
	res+=(remain+k-1)/k;
	printf("%lld\n",res);return 0;
}