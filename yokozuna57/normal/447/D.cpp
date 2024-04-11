#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
	long long n,m,k,p;
	static long long a[1002][1002];

	scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&p);
	for(long long i=0;i<n;i++){
		for(long long j=0;j<m;j++){
			scanf("%I64d",&a[i][j]);
		}
	}

	static long long MAX_r[1000010],MAX_c[1000010];
	priority_queue<long long> R,C;

	for(long long i=0;i<n;i++){
		long long sum=0;
		for(long long j=0;j<m;j++){
			sum+=a[i][j];
		}
		R.push(sum);
	}

	for(long long j=0;j<m;j++){
		long long sum=0;
		for(long long i=0;i<n;i++){
			sum+=a[i][j];
		}
		C.push(sum);
	}

	MAX_r[0]=0;
	for(long long i=1;i<=k;i++){
		MAX_r[i]=MAX_r[i-1]+R.top();
		R.push(R.top()-m*p);
		R.pop();
	}

	MAX_c[0]=0;
	for(long long i=1;i<=k;i++){
		MAX_c[i]=MAX_c[i-1]+C.top();
		C.push(C.top()-n*p);
		C.pop();
	}

	long long ret=MAX_r[0]+MAX_c[k];
	for(long long i=1;i<=k;i++){
		ret=max(ret,MAX_r[i]+MAX_c[k-i]-i*(k-i)*p);
	}

	printf("%I64d\n",ret);
}