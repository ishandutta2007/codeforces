#include <iostream>
#include <cstdio>
using namespace std;

int main () {
	int h,m,s,t1,t2;
	cin >> h >> m >> s >> t1 >> t2;
	m/=5;
	s/=5;
	if (h==12) h=0;
	if (t1==12) t1=0;
	if (t2==12) t2=0;
	if (t1 > t2) swap(t1,t2);
	if (t1 <=h && h<t2 && 
	t1 <=m && m<t2&&
	t1 <=s && s<t2) puts("YES");
	else if ( (h<t1 || h>=t2) && 
	(m<t1 || m>=t2)&&
	(s<t1 || s>=t2) ) puts("YES");
	else puts("NO");
}