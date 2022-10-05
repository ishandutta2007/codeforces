#include<bits/stdc++.h>
using namespace std;
int n,a[111],b[1111111]={0};

int main(){
	int T;
	scanf("%d",&T);
	for (int fl;T--;memset(b,0,sizeof b)){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (a[i]<=a[j]) continue;
				b[a[i]-a[j]]=1;
			}
		}
		for (int i=1;i<=10000;i++){
			fl=1;
			for (int j=1;j<=n;j++){
				if (b[i*j]){
					fl=0;
					break;
				}
			}
			if (fl){
				puts("YES");
				for (int j=1;j<=n;j++){
					printf("%d ",i*j);
				}
				break;
			}
		}
	}
}