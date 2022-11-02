#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long p,k;

int a[10000007];
int tot = 0;
int main(){
	cin >> p >> k;
	int sign = 1;
	long long pp;
	while(p > 0){
		if(sign == 1){
			pp = p / k; 
			a[++tot] = p - pp * k;
		}else{
			pp = (p + k - 1) / k;
			a[++tot] = -p + pp * k;
		}
		p = pp;
		sign ^= 1;
	}	
	cout << tot << endl;
	for(int i = 1;i <= tot;i++){
		cout << a[i] << " ";
	}
	return 0;
}