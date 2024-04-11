#include<iostream>
using namespace std;

int main(){
	int m,n;
	scanf("%d%d",&n,&m);

	static int ans[100010];

	if(m%2==0){
		ans[0]=m/2;
		for(int i=1;i<m;i++){
			if(i%2==1){
				ans[i]=ans[0]+(i+1)/2;
			}
			else {
				ans[i]=ans[0]-i/2;
			}
		}
	}
	else {
		ans[0]=(m+1)/2;
		for(int i=1;i<m;i++){
			if(i%2==0){
				ans[i]=ans[0]+i/2;
			}
			else {
				ans[i]=ans[0]-(i+1)/2;
			}
		}
	}

	for(int i=0;i<n;i++){
		printf("%d\n",ans[i%m]);
	}
}