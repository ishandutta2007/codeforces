#include <bits/stdc++.h>
using namespace std;

int n, d, h;
int main(){
	scanf("%d %d %d", &n, &d, &h);

	if(d < h)printf("-1\n");
	else if(d > 2 * h)printf("-1\n");
	else{
		if(d == h){
			if(d == 1){
				if(n == 2)printf("1 2\n");
				else printf("-1\n");
			}else{
				int cnt = 2;
				for(int i = 0, j = 1; i < d; i++){
					printf("%d %d\n", j, cnt);
					j = cnt++;
				}
				while(cnt <= n)printf("%d %d\n", 2, cnt++);
			}
		}else{
			int cnt = 2;

			for(int i = 0, j = 1; i < h; i++){
				printf("%d %d\n", j, cnt);
				j = cnt++;
			}
			for(int i = 0, j = 1; i < d - h; i++){
				printf("%d %d\n", j, cnt);
				j = cnt++;
			}

			while(cnt <= n)printf("%d %d\n", 1, cnt++);
		}
	}

	return 0;
}