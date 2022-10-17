#include<iostream>
using namespace std;

int main(){
	int n,m,a[102],b[102];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int j=0;j<m;j++)scanf("%d",&b[j]);
	int min_a=1000,max_a=0,min_b=1000;
	for(int i=0;i<n;i++){
		if(a[i]<min_a)min_a=a[i];
		if(a[i]>max_a)max_a=a[i];
	}
	for(int i=0;i<m;i++)if(b[i]<min_b)min_b=b[i];
	if(min_a*2>max_a)max_a=min_a*2;
	if(max_a<min_b)printf("%d\n",max_a);
	else printf("-1\n");
}