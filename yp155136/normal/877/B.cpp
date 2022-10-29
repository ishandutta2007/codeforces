#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 5e4 + 6;

int pre[MAX_N];

int main () {
	string s;
	cin >> s;
	int n=s.size();
	s=" "+s;
	for (int i=1;n>=i;i++) {
		pre[i] = pre[i-1] + (s[i]=='a');
	}
	int ans=pre[n];  //b is empty
	for (int i=1;n>=i;i++) {
		for (int j=i;n>=j;j++) {
			//i~j are b
			ans = max(ans, (pre[i-1]) + (j-i+1) - (pre[j]-pre[i-1]) + ((pre[n]-pre[j]) ) );
		}
	}
	printf("%d\n",ans);
}