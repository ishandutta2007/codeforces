#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

typedef long long LL;
const int MAX_Q = 1004;

map<LL,LL> mp;

int main (){
	int q;
	while (scanf("%d",&q) != EOF) {
		for (int x=0;q>x;x++) {
			int i;
			LL j,k;
			scanf("%d %I64d %I64d",&i,&j,&k);
			if (i==1) {
				LL y;
				scanf("%I64d",&y);
				while (j!=k) {
					if (j>k) {
						mp[j] += y;
						j/=2;
					}
					else if (j<k) {
						mp[k] += y;
						k/=2;
					}
				}
			}
			else {
				LL ans=0;
				while (j!=k) {
					if (j>k) {
						ans +=mp[j];
						j/=2;
					}
					else if (j<k) {
						ans+=mp[k];
						k/=2;
					}
				}
				printf("%I64d\n",ans);
			}
		}
	}
}