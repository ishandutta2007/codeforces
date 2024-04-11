#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

const int MAX_N = 1e4 + 6;

int a[MAX_N];
map<int,int> mp;

int main (){
	int n;
	while (scanf("%d",&n) != EOF) {
		int cnt=0;
		int ans=0;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			if (a[i]==i) cnt++;
			else if (!mp[a[i]]) {
				mp[a[i]]=1;
				ans++;
			}
		}
		printf("%d\n",cnt+ans/2);
		fflush(stdout);
	}
}