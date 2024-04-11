#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,ans,s;
int main(){
	scanf("%d%d",&n,&k);
	ans=s=0;
	for (int i=1;i<=n;i++){
		s+=5*i;
		if (s+k<=240) ans=i;
	}
	printf("%d",ans);
}