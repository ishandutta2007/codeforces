#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

int main(){    
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	
	if(d == 0)printf("Hermione\n");
	else if(c == 0)printf("Ron\n");
	else if(b == 0)printf("Hermione\n");
	else if(a == 0)printf("Ron\n");
	else if(f == 0)printf("Hermione\n");
	else if(e == 0)printf("Ron\n");
	else{
		if(b * d * f > a * c * e)printf("Ron\n");
		else printf("Hermione\n");
	}
	
    return 0;
}