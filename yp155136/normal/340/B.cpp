#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
using namespace std;

typedef long long LL;
typedef long double ld;
typedef pair<LL,LL> pdd;
const int MAX_N = 3e2 + 6;

pdd p[MAX_N];
pdd to_bou[MAX_N];

pdd operator-(const pdd &p1,const pdd &p2) {
	return make_pair(p1.first-p2.first,p1.second-p2.second);
}

int cross(pdd p1,pdd p2) {
	return p1.first*p2.second - p1.second*p2.first;
}

LL get_area(pdd x, pdd y,pdd z) {
	return ((x.first*y.second + y.first*z.second + z.first*x.second) - 
	        (x.first*z.second + y.first*x.second + z.first*y.second) );
}

LL __(pdd p1,pdd p2,pdd p3,pdd p4) {
	return abs((p1.first*p2.second+p2.first*p3.second+p3.first*p4.second+p4.first*p1.second)  -
	(p1.first*p4.second+p2.first*p1.second + p3.first*p2.second + p4.first*p3.second)
	
	);
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0;n>i;i++) {
		int x,y;
		cin >>x >> y;
		p[i] = make_pair(x,y);
	}
	sort(p,p+n);
	
	int sz=1;
	to_bou[0] = p[0];
	for (int i=1;n>i;i++) {
		while (sz > 1 && cross(p[i]-to_bou[sz-1],to_bou[sz-1]-to_bou[sz-2]) < 0) sz--;
		to_bou[sz++] = p[i];
	}
//	cout<<"sz = "<<sz<<endl;
	int _cnt=1;
//	to_bou[sz++] = p[n-2];
	for (int i=n-2;i>=0;i--) {
		while (_cnt > 1 && cross(p[i]-to_bou[sz-1],to_bou[sz-1]-to_bou[sz-2]) < 0) sz--,_cnt--;
		to_bou[sz++] = p[i];
		_cnt++;
	}
	sz--;
//	for (int x=0;sz>x;x++) {
//		cout<<"X = "<<x<<" , p = "<<p[x].first<<","<<p[x].second<<endl;
//	}
//	cout<<"sz = "<<sz<<endl;
	if (sz == 3) {
//		cout<<"haha "<<endl;
		set<pdd> st;
		st.insert(to_bou[0]);
		st.insert(to_bou[1]);
		st.insert(to_bou[2]);
		LL mx = -1;
		for (int i=0;n>i;i++) {
			if (st.find(p[i]) == st.end()) {
				LL a=get_area(to_bou[0],to_bou[1],p[i]);
				LL b=get_area(to_bou[2],to_bou[1],p[i]);
				LL c=get_area(to_bou[0],to_bou[2],p[i]);
				a=abs(a);
				b=abs(b);
				c=abs(c);
//				cout<<"haha i = "<<i<<" a = "<<a <<" , b = "<<b<<" , c = "<<c<<endl;
				LL _=min(min(a,b),c);
				mx = max(mx,a+b+c-_);
			}
		}
		printf("%I64d.%d\n",mx/2,((mx&1)?5:0));
		//too difficult
	}
	else {
		//too easy
		LL mx = -1;
		for (int i=0;sz>i;i++) {
			for (int j=i+1;sz>j;j++) {
				for (int k=j+1;sz>k;k++) {
					for (int l=k+1;sz>l;l++) {
						mx = max(mx,__(to_bou[i],to_bou[j],to_bou[k],to_bou[l]) );
					}
				}
			}
		}
		printf("%I64d.%d\n",mx/2,((mx&1)?5:0));
	}
}