#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int S=1;
	for (;S*S<n;S++);
	int r=n,l=n-S+1;
	for (;r>0;l-=S,r-=S){
		l=max(l,1);
		for (int i=l;i<=r;i++) printf("%d ",i);
	}
}