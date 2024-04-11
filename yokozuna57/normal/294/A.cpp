#include<iostream>
using namespace std;

int main(){
	int n,a[100+4],m,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	a[0]=0; a[n+1]=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		a[x-1]+=y-1;
		a[x+1]+=a[x]-y;
		a[x]=0;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
}