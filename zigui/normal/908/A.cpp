#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<string>
#include<ctype.h>
using namespace std;

typedef long long ll;

const int MM = 1000000007;
const int MX = 1005;

int main()
{
	string D;
	int ans = 0;
	cin >> D;
	for(char c : D){
		if( '0' <= c && c <= '9' ) ans += c&1;
		else ans += c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
	printf("%d\n", ans);
}