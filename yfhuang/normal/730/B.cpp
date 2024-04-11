#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int big[50],small[50];
char s[3];

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int tot1 = 0,tot2 = 0;
		for(int i = 1;i <= n / 2;i++){
			printf("? %d %d\n",i,i + n/2);
			fflush(stdout);
			scanf("%s",s);
			if(s[0] == '>' || s[0] == '='){
				big[++tot1] = i;
				small[++tot2] = i + n / 2;
			}else{
				big[++tot1] = i + n / 2;
				small[++tot2] = i;
			}
		}
		if(n & 1) big[++tot1] = n,small[++tot2] = n;
		int maxp = big[1];
		int minp = small[1];
		for(int i = 2;i <= tot1;i++){
			printf("? %d %d\n",maxp,big[i]);
			fflush(stdout);
			scanf("%s",s);
			if(s[0] == '>' || s[0] == '='){
			}else{
				maxp = big[i];
			}
		}
		for(int i = 2;i <= tot2;i++){
			printf("? %d %d\n",minp,small[i]);
			fflush(stdout);
			scanf("%s",s);
			if(s[0] == '>' || s[0] == '='){
				minp = small[i];
			}else{
			}
		}
		printf("! %d %d\n",minp,maxp);
		
fflush(stdout);
}
	return 0;
}