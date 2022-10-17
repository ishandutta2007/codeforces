#include <iostream>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		static int n;
		static int p[400010];
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++){
			scanf("%d",&p[i]);
		}
		p[n+1] = -1;
		
		int g = 0;
		for(int i = 1 ; i <= n ; i ++){
			g = i;
			if(p[i] != p[i+1])break;
		}
		int s = -1;
		for(int i = g+g+1 ; i <= n ; i ++){
			if(p[i] != p[i+1]){
				s = i-g;
				break;
			}
		}
		if(s == -1){
			puts("0 0 0");
			continue;
		}
		int b = -1;
		for(int i = g+s+g+1 ; i*2 <= n ; i ++){
			if(p[i] != p[i+1]){
				b = i-g-s;
			}
		}
		if(b == -1){
			puts("0 0 0");
			continue;
		}
		if((g+s+b)*2 <= n)printf("%d %d %d\n",g,s,b);
		else printf("0 0 0\n");
	}
}