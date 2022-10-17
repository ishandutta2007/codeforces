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

	long long l=1,r=n*m;
	while(l<r){
		long long s=(l+r)/2;
		
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			cnt+=min(s/i,m);
		}

		if(cnt>=k)r=s;
		else l=s+1;
	}

	printf("%I64d\n",l);
}