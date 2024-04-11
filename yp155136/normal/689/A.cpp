#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n;
	string s;
	cin >> n;
	cin >> s;
	int dx[11]={2,1,2,3,1,2,3,1,2,3,2},dy[11]={1,4,4,4,3,3,3,2,2,2,1};
	string ans="YES";
	for (int x=0;9>=x;x++) {
		if (x == s[0]-'0') continue;
		bool check=true;
		int sx=dx[x],sy=dy[x];
		for (int y=1;n>y;y++) {
			sx += dx[s[y]-'0']-dx[s[y-1]-'0'];
			sy += dy[s[y]-'0']-dy[s[y-1]-'0'];
			if (sx==2&&sy==1 || 1<=sx&&sx<=3&&2<=sy&&sy<=4) ;
			else {
				check=false;
				break;
			}
		}
		if (check)ans="NO";
	}
	cout<<ans<<endl;
}