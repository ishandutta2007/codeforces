#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

long double power(long double x,int k){
	if(k==0)return 1;
	long double tmp=power(x,k/2);
	tmp*=tmp;
	if(k%2==1)tmp*=x;
	return tmp;
}

int main(){
	int m,n;
	scanf("%d%d",&m,&n);

	long double a[100010];

	for(int i=1;i<=m;i++){
		a[i]=power((long double)i/m,n);
	}

	long double ans=a[1];

	for(int i=m;i>=2;i--){
		a[i]-=a[i-1];
		ans+=a[i]*i;
	}

	printf("%.12f\n",ans);
}