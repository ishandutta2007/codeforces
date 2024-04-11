#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		ll t;
		scanf("%lld",&t);
		if(t <= 14){
			puts("NO");
			continue;
		}
		t %= 14;
		if(1 <= t && t <= 6)puts("YES");
		else puts("NO");
	}
}