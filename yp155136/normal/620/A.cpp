#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
int main () {
	int x1,x2;
	int y1,y2;
	while (scanf("%d %d",&x1,&y1) != EOF) {
		scanf("%d %d",&x2,&y2);
		int ans=max(abs(x1-x2),abs(y1-y2));
		printf("%d\n",ans);
		
	}
}