#include<bits/stdc++.h>
using namespace std;

int n,a,b;

int main(){
	cin>>n>>a>>b;
	for (int i=0;i*a<=n;++i) if ((n-a*i)%b==0){
		puts("YES");
		printf("%d %d",i,(n-a*i)/b);
		return 0;
	}
	puts("NO");
}