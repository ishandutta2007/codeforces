#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
const int maxn = 1005;
int a[maxn], b[maxn], c[maxn], d[maxn];

int main(){
	while(cin >> n){
		long long x = 0, y = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i];
			x += a[i];
			y += b[i];
		}
		for(int i = 1;i <= n;i++){
			cin >> c[i] >> d[i];
			x += c[i];
			y += d[i];
		}
		x /= n;
		y /= n;
		cout << x << " " << y << endl;
	}
	return 0;
}