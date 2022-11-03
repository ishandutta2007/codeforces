#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e6 + 5;
typedef long long LL;

LL l[maxn],r[maxn];
char s[maxn];

int main(){
	int tot = 0;
	int n;
	cin >> n;
	scanf("%s",s + 1);
	tot = 0;
	l[0] = n + 1;
	for(int i = n;i >= 1;i--){
		if(s[i] == 'D'){
			tot++;
			l[tot] = l[tot - 1] + i;
		}
	}
	tot = 0;
	r[0] = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == 'U'){
			tot++;
			r[tot] = r[tot - 1] + i;
		}
	}
	int frontu = 0;
	int backd = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == 'D') backd++;
	}
	for(int i = 1;i <= n;i++){
		if(s[i] == 'U'){
			frontu++;
			if(frontu <= backd){
				cout << (l[backd] - l[backd - frontu]) * 2 - 2 * r[frontu] + r[frontu] - r[frontu - 1] + r[0] << " ";
			}else{
				cout << l[backd] * 2 - l[0] - 2 * (r[frontu] - r[frontu - backd - 1]) + (r[frontu] - r[frontu - 1]) << " ";
			}
		}else{
			if(backd <= frontu){
				cout << l[backd] * 2 - l[0] - l[backd] + l[backd - 1] - 2 * (r[frontu] - r[frontu - backd]);
			}else{
				cout << 2 * (l[backd] - l[backd - frontu - 1]) - l[backd] + l[backd - 1] - r[frontu] * 2 + r[0];
			}
			cout << " ";
			backd--;
		}
	}
	return 0;
}