#include<iostream>
using namespace std;

int main(){
	int n,m,y=0,t,a[100000+2],p,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n+1;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&p,&x);
			a[p]=x-y;
		}
		if(t==2){
			scanf("%d",&p);
			y+=p;
		}
		if(t==3){
			scanf("%d",&p);
			printf("%d\n",a[p]+y);
		}
	}
}