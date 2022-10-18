#include <bits/stdc++.h>
using namespace std;

long long ax, ay, bx, by, cx, cy;
long long cross(long long x1, long long y1, long long x2, long long y2){
    return x1 * y2 - x2 * y1;
}
int main(){
	scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &ax, &ay, &bx, &by, &cx, &cy);
	
	long long d1 = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
	//long long d2 = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy);
	long long d3 = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
	long long c = cross(bx - ax, by - ay, cx - ax, cy - ay);
	
	
	if(d1 == d3 && c != 0)printf("Yes\n");
	else printf("No\n");
	
	return 0;
}