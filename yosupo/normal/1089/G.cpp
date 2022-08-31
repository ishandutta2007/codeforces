#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for(int _=0;_<t;_++){
		int K;
		scanf("%d",&K);
		int cnt=0,a[7];
		for(int j=0;j<7;j++){
			scanf("%d",a+j);
			cnt+=a[j];	
		}
		int p=(K-1)/cnt,q=(K-1)%cnt+1;
		int ans=7;
		for(int j=0;j<7;j++){
			int c=0;
			for(int k=1;k<=7;k++){
				c+=a[(j+k)%7];
				if(c==q){
					ans=min(ans,k);
				}
			}
		}
		printf("%d\n",p*7+ans);
	}
	
}