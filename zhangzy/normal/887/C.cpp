#include<bits/stdc++.h>
#define win exit(0*puts("YES"))
#define ok(q,w,e,r) (a[q]==a[w]&&a[w]==a[e]&&a[e]==a[r])
#define all(x) ok(x*4-3,x*4-2,x*4-1,x*4)
int a[33];
int main(){
	for (int i=1;i<=24;i++) std::cin>>a[i];
	if (all(4)&&all(5)&&(ok(1,3,21,23)&&ok(22,24,10,12)&&ok(9,11,6,8)&&ok(5,7,2,4)||ok(1,3,6,8)&&ok(22,24,2,4)&&ok(9,11,21,23)&&ok(5,7,10,12))) exit(0*puts("YES"));
	if (all(1)&&all(3)&&(ok(13,14,7,8)&&ok(5,6,19,20)&&ok(17,18,23,24)&&ok(21,22,15,16)||ok(13,14,23,24)&&ok(5,6,15,16)&&ok(17,18,7,8)&&ok(21,22,19,20))) exit(0*puts("YES"));
	if (all(2)&&all(6)&&(ok(1,2,14,16)&&ok(13,15,9,10)&&ok(11,12,17,19)&&ok(18,20,3,4)||ok(1,2,17,19)&&ok(13,15,3,4)&&ok(11,12,14,16)&&ok(18,20,9,10))) exit(0*puts("YES"));
	puts("NO");
}