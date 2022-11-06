#include<stdio.h>
#include<algorithm>
int a[100002],n,s=0,f=0;
long long cnt=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt+=a[i]-i-1;
	}std::sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			if(++s>=2)f=1;
			if(a[i]==0)f=1;
			if(i!=1&&a[i-1]==a[i]-1)f=1;
		}
	}
	printf("%snb",f?"csl":(cnt&1?"sjf":"csl"));
}