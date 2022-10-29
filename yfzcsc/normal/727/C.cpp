#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int a[5010],n;
int get(int a,int b){
	int ans;
	printf("? %d %d\n",a,b);
	fflush(stdout);
	scanf("%d",&ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	int x=get(1,n),y=get(1,2),z=get(2,n);
	a[1]=(x+y-z)/2;
	a[2]=y-a[1];
	a[n]=x-a[1];
	for(int i=3;i<n;++i){
		int x=get(i-1,i);
		a[i]=x-a[i-1];
	}
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
}