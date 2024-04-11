#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

const int MAX_P = 8;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int _[MAX_P]={0},__[MAX_P]={0},cnt[MAX_P]={0};
		for (int i=1;n>=i;i++) {
			int ala;
			scanf("%d",&ala);
			_[ala]++;
			cnt[ala]++;
		}
		for (int i=1;n>=i;i++) {
			int ala;
			scanf("%d",&ala);
			__[ala]++;
			cnt[ala]++;
		}
		bool check=true;
		for (int i=1;5>=i;i++) {
			if (cnt[i]%2 !=0 )check=false;
		}
		if (!check) puts("-1");
		else {
			int ans=0;
			for (int i=1;5>=i;i++) {
				ans += abs(_[i]-__[i])/2;
			}
			printf("%d\n",ans/2);
		}
		
	}
}