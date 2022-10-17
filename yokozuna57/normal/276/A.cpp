#include<iostream>
using namespace std;

int main(){
	int n,k,a,b,ans;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		int c=0;
		if(b<=k)c=a;
		if(b>k)c=a+k-b;
		if(i==0||c>ans)ans=c;
	}
	printf("%d\n",ans);
}