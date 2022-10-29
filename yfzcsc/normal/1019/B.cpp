#include<bits/stdc++.h>
using namespace std;
int n;
int ask(int n){
	printf("? %d\n",n);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void ret(int n){
	printf("! %d\n",n);
	fflush(stdout);
	exit(0);
}
int main(){
	scanf("%d",&n);
	if(n/2&1)ret(-1);
	int l1=ask(1),r1=ask(n/2+1);
	int l2=r1,r2=l1;
	int L=2,R=n/2;
	if(l1==r1)ret(1);
	while(true){
		int mid=(L+R)/2;
		int z=ask(mid),z2=ask(mid+n/2);
		if(z==z2)ret(mid);
		if(z>z2){
			if(r2>r1){
				l1=z,l2=z2;
				L=mid+1;
			} else if(l2>l1){
				r1=z,r2=z2;
				R=mid-1;
			}
		} else {
			if(r2<r1){
				l1=z,l2=z2;
				L=mid+1;
			} else if(l2<l1){
				r1=z,r2=z2;
				R=mid-1;
			}
		}
	}
}