#include<iostream>
using namespace std;

int main(){
	int n,a[10],k=0,t=1000000000;
	scanf("%d",&n);
	if(n==1000000000)printf("NO");
	else {
		for(;t>=10;t/=10){
			if(k!=0){a[k]=((n%t)-(n%(t/10)))/(t/10); k++;}
			else {
				if(((n%t)-(n%(t/10)))/(t/10)!=0){a[k]=((n%t)-(n%(t/10)))/(t/10); k++;}
			}
		}
		bool c=(a[0]==1);
		for(int i=0;i<k;i++)if(a[i]!=1&&a[i]!=4)c=false;
		for(int i=0;i<k-2;i++)if(a[i]==4&&a[i+1]==4&&a[i+2]==4)c=false;
		if(c)printf("YES");
		else printf("NO");
	}
}