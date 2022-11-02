#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 5;
int a[maxn];

int main(){
	int n;
	cin >> n;
	bool flag = true;
	int M = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		M = max(M,a[i]);
	}
	bool flag1 = 0;
	for(int i = 2;i <= n;i++){
		if(a[i] == a[i - 1]) flag1 = 1;
	}
	if(flag1){
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 2;i <= n;i++){
		if(abs(a[i] - a[i - 1]) != 1) 
			flag = false;
	}
	if(flag){
		cout << "YES" << endl;
		cout << M << " " << 1 << endl;
	}else{
		int dif = -1;
		flag = true;
		for(int i = 2;i <= n;i++){
			if(abs(a[i] - a[i - 1]) != 1){
				if(dif == -1)
					dif = abs(a[i] - a[i - 1]);
				else{
					if(dif != abs(a[i] - a[i - 1])){
						flag = false;
					}	
				}
			}
		}
		if(!flag){
			cout << "NO" << endl;
		}else{
			for(int i = 2;i <= n;i++){
				if(abs(a[i] - a[i - 1]) == 1){
					int mx = min(a[i],a[i - 1]);
					if(mx % dif == 0) flag = false;
				}
			}
			if(flag){
				cout << "YES" << endl;
				cout << (M + dif - 1) / dif << " " << dif << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}