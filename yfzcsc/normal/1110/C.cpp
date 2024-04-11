#include<bits/stdc++.h>
using namespace std;
int a[]={0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845
		,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
	
int br(int i){
	int A=0;
	for(int j=1;j<i;++j)A=max(A,__gcd(i&j,i^j));
	return A;
}
int main(){
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int k=0,x;
		scanf("%d",&x);
		for(int i=1;i<=25;++i)if(x==(1ll<<i)-1){
			printf("%d\n",a[i-1]);
			goto nxt;
		}
		while(x)x>>=1,k++;
		printf("%d\n",(1<<k)-1);
		nxt:;
	}
}