#include <stdio.h>
int n, l, r;
int a[100001];
int b[100001];
int cnt[100001];
int main(){
	scanf("%d %d %d", &n, &l, &r);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(int i=1; i<=n; i++)
		scanf("%d", &b[i]);
	for(int i=1; i<l; i++)
		if(a[i]!=b[i]){
			printf("LIE");
			return 0;
		}
	for(int i=n; i>r; i--)
		if(a[i]!=b[i]){
			printf("LIE");
			return 0;
		}
	for(int i=l; i<=r; i++){
		cnt[a[i]]++;
		cnt[b[i]]--;
	}
	for(int i=1; i<=n; i++){
		if(cnt[i]){
			printf("LIE");
			return 0;
		}
	}
	printf("TRUTH");
}