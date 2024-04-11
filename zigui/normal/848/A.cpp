#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int MX = 100005;

int D[MX];

int main(){
	int N;
	char c = 'a';
	scanf("%d", &N);
	if( N == 0 ) return !printf("a");
	while(N){
		int K = sqrt(N*2);
		if( N == 1 ) K = 2;
		N -= K*(K-1) / 2;
		for(int k = 1; k <= K; k++) printf("%c", c);
		c++;
	}
}