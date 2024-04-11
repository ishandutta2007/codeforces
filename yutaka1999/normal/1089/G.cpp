#include <iostream>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;--T){
		int K;
		int a[7];
		int A = 0;
		scanf("%d",&K);
		for(int i = 0 ; i < 7 ; i ++){
			scanf("%d",&a[i]);
			A += a[i];
		}
		int ret = (K/A)*7;
		int r = K%A;
		if(r == 0){
			ret -= 7;
			r = A;
		}
		if(r != 0){
			for(int d = 1 ; d <= 7 ; d ++){
				bool b = false;
				for(int i = 0 ; i < 7 ; i ++){
					int sum = 0;
					for(int j = i ; j < i+d ; j ++){
						sum += a[j%7];
					}
					b |= sum >= r;
				}
				if(b){
					ret += d;
					break;
				}
			}
		}
		printf("%d\n",ret);
	}
}