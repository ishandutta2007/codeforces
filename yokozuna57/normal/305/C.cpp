#include<iostream>
using namespace std;

int main(){
	int n,a[100000+2],b[100000+2],k=1,ans=0,m=0;
	scanf("%d%d",&n,&a[0]);
	b[0]=1;
	for(int i=1;i<n;i++){
		scanf("%d",&a[k]);
		if(a[k]==a[k-1])b[k-1]++;
		else {b[k]=1; k++;}
	}
	a[k]=-1;
	for(int i=0;i<k;i++){
		ans+=b[i]%2;
		b[i]-=b[i]%2;
		if(b[i]!=0){
			if(a[i+1]==a[i]+1)b[i+1]+=b[i]/2;
			else {a[i]+=1; b[i]/=2; i--;}
		}
	}
	printf("%d\n",a[k-1]-ans+1);
}