#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 5;

char s[maxn];

int main(){
	int n;
	cin >> n;
	scanf("%s",s);
	int n1 = 0,n2 = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'A') n1++;
		if(s[i] == 'D') n2++;
	}
	if(n1 > n2) printf("Anton\n");
	else if(n1 == n2) printf("Friendship\n");
	else printf("Danik\n");
	return 0;
}