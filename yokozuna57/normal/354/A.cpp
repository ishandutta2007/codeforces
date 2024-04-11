#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,l,r,p,q,w[100000+2],ans=2100000000,sum=0,sub=0;
	scanf("%d%d%d%d%d",&n,&l,&r,&p,&q);
	for(int i=0;i<n;i++){scanf("%d",&w[i]); sum+=w[i];}
	for(int i=0;i<=n;i++){
		int ret=sum*r+sub*l;
		if(i<=n-i){ret+=max(0,n-i-i-1)*q;}
		else {ret+=max(0,i-n+i-1)*p;}
		if(ret<ans)ans=ret;
		if(i!=n){sum-=w[i]; sub+=w[i];}
	}
	printf("%d\n",ans);
}