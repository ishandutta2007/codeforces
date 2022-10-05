#include<bits/stdc++.h>
using namespace std;
long long l,r,x,y,k;

int main(){
	cin>>l>>r>>x>>y>>k;
	for (long long i=x;i<=y;i++){
		if (i*k>=l&&i*k<=r){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}