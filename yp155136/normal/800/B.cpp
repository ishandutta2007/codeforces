#include <iostream>
#include <stdio.h>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;

typedef long double ld;
typedef pair<ld,ld> pdd;
const int MAX_N = 1e3 +6;

pdd operator-(const pdd &p1,const pdd &p2) {
	return make_pair(p1.first-p2.first,p1.second-p2.second);
}

ld dot(pdd a,pdd b) {
	return a.first*b.first + a.second*b.second;
}



pdd p[MAX_N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0;n>i;i++) {
		cin >> p[i].first >> p[i].second;
	}
	p[n] = p[0];
	p[n+1] = p[1];
	ld mn = 1e18+6;
	for (int i=0;n>i;i++) {
		ld area=fabs(p[i].first*p[i+1].second+p[i+1].first*p[i+2].second+p[i+2].first*p[i].second
		-p[i].first*p[i+2].second-p[i+1].first*p[i].second-p[i+2].first*p[i+1].second);
//		cout<<"area = "<<area<<endl;
		ld dis=sqrt(dot(p[i]-p[i+2],p[i]-p[i+2]));
//		cout<<"dis = "<<dis<<endl;
		mn = min(mn,(area*2)/dis/2);
	}
	cout<<fixed<<setprecision(14)<<mn/2<<endl;
}