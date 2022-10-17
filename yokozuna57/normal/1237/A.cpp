#include <iostream>
using namespace std;

int main(){
	static int n;
	static int a[20010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
	}
	
	static int sum = 0;
	static int ret[20010];
	static bool b[20010];
	for(int i = 0 ; i < n ; i ++){
		if(a[i] >= 0){
			ret[i] = a[i]/2;
			b[i] = a[i]%2 == 1;
		}
		else {
			if((-a[i])%2 == 0){
				ret[i] = a[i]/2;
				b[i] = false;
			}
			else {
				ret[i] = a[i]/2-1;
				b[i] = true;
			}
		}
		sum += ret[i];
	}
	
	for(int i = 0 ; i < n ; i ++){
		if(sum < 0 && b[i]){
			ret[i] ++;
			sum ++;
		}
	}
	for(int i = 0 ; i < n ; i ++){
		printf("%d\n",ret[i]);
	}
}