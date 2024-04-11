#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n,a,b;

int main(){
	cin >> n >> a >> b;
	int x = -1,y = -1;
	for(int i = 0;i * a <= n;i++){
		if((n - i * a) % b == 0){
			x = i,y = (n - i * a) / b;
		}
	}
	if(x == -1) cout << -1 << endl;
	else{
		int now = 1;
		for(int i = 1;i <= x;i++){
			for(int j = 1;j <= a;j++){
				printf("%d ",now + j % a);
			}
			now += a;
		}
		for(int i = 1;i <= y;i++){
			for(int j = 1;j <= b;j++){
				printf("%d ",now + j % b);
			}
			now += b;
		}
	}
	return 0;
}