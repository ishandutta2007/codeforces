#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		string s;
		cin >> s;
		int cnt[2] = {};
		int sum = 0;
		for(int i = 0 ; i < s.size() ; i ++){
			if(s[i] == '0')cnt[0] ++;
			if((s[i]-'0')%2 == 0)cnt[1] ++;
			sum += s[i]-'0';
		}
		if(sum%3 == 0 && cnt[0] >= 1 && cnt[1] >= 2){
			puts("red");
		}
		else puts("cyan");
	}
}