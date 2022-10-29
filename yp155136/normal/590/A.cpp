#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 5e5 +6;

bool a[MAX_N];
bool ans[MAX_N];

int main () {
	int n;
	scanf("%d",&n);
	vector<pii> v;
	int l=1;
	for (int i=1;n>=i;i++) {
		scanf("%d",&a[i]);
		if (i>1) {
			if (a[i] == a[i-1]) {
				v.push_back(make_pair(l,i-1));
				l=i;
			}
		}
	}
	v.push_back(make_pair(l,n));
	int mx=0;
	for (pii p:v) {
		int l=p.first,r=p.second;
//		cout<<"l = "<<l<<" , r = "<<r<<endl;
		if (r-l+1 <= 2) {
			ans[l] = a[l];
			ans[r] = a[r];
		}
		else {
			mx = max(mx,(r-l)/2);
			if ((r-l+1)%2 == 0) {
				int mid=(l+r)>>1;
				for (int i=l;mid>=i;i++) {
					ans[i] = a[l];
				}
				for (int i=mid+1;r>=i;i++) {
					ans[i] = a[r];
				}
			}
			else {
				for (int i=l;r>=i;i++) {
					ans[i] = a[l];
				}
			}
		}
	}
	printf("%d\n",mx);
	printf("%d",ans[1]);
	for (int i=2;n>=i;i++) printf(" %d",ans[i]);
	puts("");
}