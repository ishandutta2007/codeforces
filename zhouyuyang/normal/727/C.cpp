#include<bits/stdc++.h>
int a[5005];
int b[5005];
int n;
using namespace std;
int query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++)
		a[i]=query(i,i+1);
	if (n&1){
		a[n]=query(1,n);
		int s=0;
		for (int i=1;i<=n;i++)
			s+=a[i];
		s/=2;
		for (int i=1;i<n;i+=2)
			s-=a[i];
		b[n]=s;
		for (int i=n-1;i;i--)
			b[i]=a[i]-b[i+1];	
	}
	else{
		a[n]=query(1,3);
		b[1]=(a[n]+a[1]+a[2])/2-a[2];
		for (int i=2;i<=n;i++)
			b[i]=a[i-1]-b[i-1];
	}
	printf("!");
	for (int i=1;i<=n;i++)
		printf(" %d",b[i]);
}