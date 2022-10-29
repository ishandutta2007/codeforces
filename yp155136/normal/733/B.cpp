#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

const int MAX_N = 1e5 + 6;

int l[MAX_N],r[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int _=0,__=0;
		for (int i=1;n>=i;i++) {
			scanf("%d %d",&l[i],&r[i]);
			_ += l[i];
			__+= r[i];
		}
		int mx_id=0;
		int mx = abs(_-__);
		for (int i=1;n>=i;i++) {
			__ -= (r[i]-l[i]);
			_-= (l[i]-r[i]);
			if (abs(_-__) > mx) {
				mx = abs(_-__);
				mx_id=i;
			}
			__ += (r[i]-l[i]);
			_+= (l[i]-r[i]);
		}
		printf("%d\n",mx_id);
	}
}