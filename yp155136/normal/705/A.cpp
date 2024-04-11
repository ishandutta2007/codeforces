#include <iostream>
#include <stdio.h>
using namespace std;

int main (){
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>=x;x++) {
			if (x%2==1) printf("I hate ");
			else if (x%2==0) printf("I love ");
			
			if (x!=n) printf("that ");
			else printf("it\n");
		}
	}
}