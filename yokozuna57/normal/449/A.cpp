#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int main(){
	long long n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);

	long long ret=-1;
	long long a=0;
	for(long long i=max(a,k-m+1);i<=min(n-1,k);i++){
		i=min(min(n-1,k),n/(n/(i+1))-1);
		ret=max(ret,(n/(i+1))*(m/(k-i+1)));
	}

	printf("%I64d\n",ret);
}