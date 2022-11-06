#include<stdio.h>
int r[100002],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		r[a]++;r[b]++;
	}
	for(int i=1;i<=n;i++){
		if(r[i]==2)return printf("NO")&0;
	}
	printf("YES");
}