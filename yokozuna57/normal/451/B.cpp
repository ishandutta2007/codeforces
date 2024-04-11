#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int a[100010];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	bool b=false;
	bool c=true;
	int ret0=n,ret1=n;

	for(int i=0;i+1<n;i++){
		if(a[i]>a[i+1]){
			if(c){
				if(b){ printf("no\n"); return 0; }
				else { ret0=i+1; b=true; c=false; }
			}
		}
		else {
			if(!c){
				ret1=i+1;
			}
			c=true;
		}
	}

	int bb[100010];
	for(int i=1;i<=n;i++)bb[i]=a[i-1];

	for(int i=ret0;i<=ret1;i++){
		bb[i]=a[ret0+ret1-i-1];
	}

	bool d=true;
	for(int i=1;i<n;i++){
		if(bb[i]>bb[i+1])d=false;
	}
	if(!d)printf("no\n");
	else printf("yes\n%d %d\n",ret0,ret1);
}