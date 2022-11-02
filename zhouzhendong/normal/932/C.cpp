#include <cstring>
#include <cstdio>
#include <cmath>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=1000005;
int n,A,B,res[N];
int main(){
	scanf("%d%d%d",&n,&A,&B);
	int flag=0,a,b;
	for (int i=0;i*A<=n;i++){
		if ((n-i*A)%B==0){
			flag=1;
			a=i,b=(n-i*A)/B;
			break;
		}
	}
	if (!flag){
		puts("-1");
		return 0;
	}
	int now=0;
	for (int i=1;i<=a;i++){
		for (int j=now+1;j<now+A;j++)
			res[j]=j+1;
		res[now+A]=now+1;
		now+=A;
	}
	for (int i=1;i<=b;i++){
		for (int j=now+1;j<now+B;j++)
			res[j]=j+1;
		res[now+B]=now+1;
		now+=B;
	}
	for (int i=1;i<=n;i++)
		printf("%d ",res[i]);
	return 0;
}