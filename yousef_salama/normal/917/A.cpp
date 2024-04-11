#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;

char s[MAXN];
int n;

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	int res = 0;
	for(int i = 0; i < n; i++){
		int c = 0, d = 0;
		for(int j = i; j < n; j++){
			if(s[j] == '(')d++;
			else if(s[j] == ')'){
				while(d <= 0 && c > 0){
					d += 2;
					c--;
				}
				if(d <= 0)break;
				d--;
			}else{
				if(d <= 0)d++;
				else{
					d--;
					c++;
				}
			}
			res += (d == 0);
		}
	}
	printf("%d\n", res);
	
	return 0;
}