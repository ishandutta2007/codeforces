#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int a[50],n,i,s;
int main(){
	scanf("%d",&n);
	i=1;
	a[1]=1;
	s=1;
	while (s<=n){
		i++;
		s+=i;
		a[i]=i;
	}
	s-=i;
	i--;
	printf("%d\n",i);
	for (int j=1;j<=n-s;j++) a[i-j+1]++;
	for (int j=1;j<=i;j++) printf("%d ",a[j]);
	return 0;
}