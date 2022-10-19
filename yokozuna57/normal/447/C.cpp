#include<iostream>
using namespace std;

int main(){
	int n;
	static int a[100010]={0};
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}

	static int b[100010]={0};
	static int c[100010]={0};

	for(int i=n;i>=1;i--){
		if(a[i]<a[i+1])b[i]=b[i+1]+1;
		else b[i]=1;
	}

	for(int i=1;i<=n;i++){
		if(a[i-1]<a[i])c[i]=c[i-1]+1;
		else c[i]=1;
	}

	int ret=min(2,n);
	
	for(int i=1;i<=n;i++){
		if(a[i-1]+1<a[i+1])ret=max(ret,c[i-1]+1+b[i+1]);
		else ret=max(ret,max(c[i-1],b[i+1])+1);
	}

	printf("%d\n",ret);
}