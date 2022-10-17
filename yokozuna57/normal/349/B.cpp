#include<iostream>
using namespace std;

int main(){
	int n,a[10],mi=1000000,ma,ans;
	scanf("%d",&n);
	for(int i=1;i<=9;i++){
		scanf("%d",&a[i]);
		if(mi>a[i])mi=a[i];
	}
	if(n<mi)printf("-1");
	while(n>=mi){
		ma=n%mi+mi;
		int la=0;
		for(int i=1;i<=9;i++){
			if(a[i]<=ma){la=a[i]; ans=i;}
		}
		printf("%d",ans);
		n-=la;
	}	
}