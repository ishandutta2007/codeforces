#include<bits/stdc++.h>
using namespace std;

int n,x,p=200003,mod=131071,t;
int a[23];

bool same(){
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if (a[i]==a[j]) return 1;
		}
	}return 0;
}

int main(){
	srand(time(0));
	cin>>n>>x;
	if (n==2&&x==0){
		puts("NO");return 0;
	}
	puts("YES");
	if (n==1){
		cout<<x;return 0;
	}
	while (n>7){
		n-=4;
		for (int i=1;i<=4;i++){
			printf("%d ",++p);
		}
	}
	while (same()){
		t=x;
		for (int i=1;i<n;i++){
			a[i]=rand()%mod+1;
			t^=a[i];
		}
		a[n]=t;
	}
	for (int i=1;i<=n;printf("%d ",a[i++]));
}