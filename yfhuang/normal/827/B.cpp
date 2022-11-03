#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int n,k;

bool check(int x){
	int d = x / 2;
	return 1LL * (k - 2) * d + 1LL * (x + 1) >= 1LL * n;
}

int main(){
	while(cin >> n >> k){
		int l = 1,r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
		for(int i = 1;i <= l;i++){
			printf("%d %d\n",i,i + 1);
		}
		int root = (l + 2) / 2;
		//int left = n - (l + 1);
		int now = l + 2;
		for(int i = now;i < now + k - 2;i++){
			printf("%d %d\n",root,i);
		}
		for(int i = now + k - 2;i <= n;i++){
			printf("%d %d\n",i,i - (k - 2));
		}
	}
	return 0;
}