#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int get(int n,int k){
	if(n<0)return 0;
	return (n%k==0?n/k:n/k+1);
}
int main(){
	int n,t,k,d;
	scanf("%d%d%d%d",&n,&t,&k,&d);
	if(get(n,k)*t<=max(d+t,get(n-k,k)*t))printf("NO");
	else puts("YES");
}