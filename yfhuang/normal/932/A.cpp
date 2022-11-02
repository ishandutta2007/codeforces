#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	for(int i = 0;i < s.length();i++){
		putchar(s[i]);
	}
	for(int i = s.length() - 1;i >= 0;i--){
		putchar(s[i]);
	}
	return 0;
}