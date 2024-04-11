#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200010],b[200010];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	sort(a,a+n);
	for(int i=0;i<m;i++){
		printf("%d%c",(int)(upper_bound(a,a+n,b[i])-a),(i+1==m)?'\n':' ');
	}
}