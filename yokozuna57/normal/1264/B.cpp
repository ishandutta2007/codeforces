#include <iostream>
using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if((a+c)-(b+d) >= 2 || (b+d)-(a+c) >= 2){
		puts("NO");
		return 0;
	}
	
	static int n = a+b+c+d;
	static int ret[100010];
	if(a+c > b+d){
		for(int i = 0 ; i < n ; i ++){
			ret[i] = 2-(i&1);
		}
	}
	else {
		for(int i = 0 ; i < n ; i ++){
			ret[i] = 1+(i&1);
		}
	}
	int loc = 0;
	for(int i = 0 ; i < d ; i ++){
		while(loc < n && ret[loc] != 1)loc ++;
		if(loc >= n){
			puts("NO");
			return 0;
		}
		ret[loc] = 3;
	}
	loc = n-1;
	for(int i = 0 ; i < a ; i ++){
		while(loc >= 0 && ret[loc] != 2)loc --;
		if(loc < 0){
			puts("NO");
			return 0;
		}
		ret[loc] = 0;
	}
	for(int i = 0 ; i+1 < n ; i ++){
		if(abs(ret[i]-ret[i+1]) != 1){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i = 0 ; i < n ; i ++){
		printf("%d%c",ret[i],(i+1==n)?'\n':' ');
	}
}