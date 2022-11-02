#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
const int maxn = 1e5 + 5;
int a[maxn];
int main(){
	cin  >> n;
	for(int i = 1;i <= n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	bool flag = true;
	for(int i = 1e5;i >= 1;i--){
		if(a[i] & 1) flag = false;
	}
	if(flag) printf("Agasa\n");
	else printf("Conan\n");
	return 0;
}