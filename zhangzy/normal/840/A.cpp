#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
int n,a[200200],ans[200200];
struct B{
	int v,pos;
}b[200200];

bool cmp(B b1,B b2){
	return b1.v<b2.v;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i].v);
		b[i].pos=i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++){
		ans[b[i].pos]=a[n+1-i];
	}
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}