#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
ll ans;
int n,x,hea[1111111]={0};

int main(){
	scanf("%d",&n);
	ans=-n;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		ans+=(ll)(i-hea[x])*(n-i+1)*2;
		hea[x]=i;
	}
	printf("%.10lf\n",(db)ans/((db)n*n));
}