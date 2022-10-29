#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	LL n;
	while (scanf("%I64d",&n) != EOF) {
		string s;
		cin >> s;
		LL ans=0;
		LL base=1;
		int sz=s.size();
		LL now=0;
		LL now_base=1;
		LL last=0;
		for (int x=sz-1;x>=0;x--) {
			LL tmp=(s[x]-'0')*now_base+now;
			if (tmp>=n) {
				ans += now*base;
				base*=n;
				now_base=10;
				LL tmpnow=now;
				/*if (now==0) {
					now=s[x]-'0';
					continue;
				}*/
				now=(s[x]-'0');
				bool check=false;
				for (int y=x+1;sz>y;y++) {
					if (s[y]=='0' && !check) {
						now*=10;
						now_base*=10;
						if (now>=n) {
							now/=10;
							now_base/=10;
							check=true;
						}
					}
					else if (s[y]!='0')break;
					if (check) base*=n;
				}
				if (check && tmpnow==0) base/=n;
			}
			else {
				now=tmp;
				now_base*=10;
			}
			//cout<<"x = "<<x<<" ,ans = "<<ans<<endl;
		}
		ans += now*base;
		printf("%I64d\n",ans);
	}
}