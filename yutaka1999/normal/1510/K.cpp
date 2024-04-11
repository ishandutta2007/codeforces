#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	n*=2;
	vector <int> A(n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		A[i]--;
	}
	int ret=n*10;
	for(int t=0;t<2;t++){
		vector <int> B=A;
		for(int j=t;j<=2*n+t;j++){
			bool up=true;
			for(int k=0;k<n;k++){
				if(B[k]!=k) up=false;
			}
			if(up){
				ret=min(ret,j);
				break;
			}
			if(j%2==t){
				for(int k=0;k<n;k+=2){
					swap(B[k],B[k+1]);
				}
			} else{
				for(int k=0;k<n/2;k++){
					swap(B[k],B[k+n/2]);
				}
			}
		}
		for(int k=0;k<n/2;k++) swap(A[k],A[k+n/2]);
	}
	printf("%d\n",ret==n*10?-1:ret);
}