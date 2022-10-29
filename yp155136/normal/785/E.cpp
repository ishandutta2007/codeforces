#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;
const int MAX_N = 2e5+ 1342;
const int MAGIC = 578;

vector<int> v[MAGIC];
int a[MAX_N];

int main () {
	int n,q;
	while (scanf("%d %d",&n,&q) != EOF) {
		int group = 1021;
//		cout<<"group = "<<group<<endl;
		for(int i=0;n>i;i++) {
			a[i] = i+1;
		}
		for (int i=0;group*(n/group+1)>=i;i++) {
			a[i] = i+1;
			v[i/group].push_back(a[i]);
		}
		LL ans=0;
		int totgroup=n/group+1;
//		cout<<"totgroup = "<<totgroup<<endl;
		
		for (int i=0;q>i;i++) {
//			for (int i=0;totgroup>=i;i++) {
//				cout<<"i = "<<i<<endl;
//				for (auto j:v[i]) {
//					cout<<" "<<j<<" ";
//				}
//				cout<<endl;
//			}
			int x,y;
			scanf("%d %d",&x,&y);
			if (x==y) {
				printf("%I64d\n",ans);
				continue;
			}
			x--;
			y--;
			if (x>y) swap(x,y);
//			cout<<"x = "<<x<<" , y = "<<y<<endl;
//			cout<<"start = "<<ans<<endl;
			//group x lies in x/group
			int _=x/group;
			for (int i=_*group;x>i;i++) {
				if (a[i] > a[x]) {
					ans--;
				}
			}
			for (int i=0;_>i;i++) {
				int val=a[x];
				int pos=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
				ans -= (group-pos);
			}
			for (int i=x+1;group*_+group>i;i++) {
				if (a[i] < a[x]) {
					ans--;
				}
			}
			for (int i=_+1;i<=totgroup;i++) {
				int val=a[x];
				int pos=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
				ans -= (pos);
			}
			_=y/group;
			for (int i=_*group;y>i;i++) {
				if (a[i] > a[y]) {
					ans--;
				}
			}
			for (int i=0;_>i;i++) {
				int val=a[y];
				int pos=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
				ans -= (group-pos);
			}
			for (int i=y+1;_*group+group>i;i++) {
				if (a[i] < a[y]) {
					ans--;
				}
			}
			for (int i=_+1;i<=totgroup;i++) {
				int val=a[y];
				int pos=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
				ans -= (pos);
			}
			if (a[x] > a[y]) ans++;
//			cout<<"haha"<<endl;
//			cout<<"ans = "<<ans<<endl;
			
			if (x/group != y/group) {
				_ = x/group;
				int val=a[x];
				int pos=lower_bound(v[_].begin(),v[_].end(),val) - v[_].begin();
				v[_][pos] = a[y];
				if (pos > 0 && v[_][pos] < v[_][pos-1]) {
					while (pos > 0 && v[_][pos] < v[_][pos-1] ) {
						swap(v[_][pos],v[_][pos-1]);
						pos--;
					}
				}
				else if (pos < group-1 && v[_][pos] > v[_][pos+1]) {
					while (pos < group-1 && v[_][pos] > v[_][pos+1]) {
						swap(v[_][pos],v[_][pos+1]);
						pos++;
					}
				}
				_ = y/group;
				val=a[y];
				pos=lower_bound(v[_].begin(),v[_].end(),val) - v[_].begin();
				v[_][pos] = a[x];
				if (pos > 0 && v[_][pos] < v[_][pos-1]) {
					while (pos > 0 && v[_][pos] < v[_][pos-1] ) {
						swap(v[_][pos],v[_][pos-1]);
						pos--;
					}
				}
				else if (pos < group-1 && v[_][pos] > v[_][pos+1]) {
					while (pos < group-1 && v[_][pos] > v[_][pos+1]) {
						swap(v[_][pos],v[_][pos+1]);
						pos++;
					}
				}
			}
			swap(a[x],a[y]);
			swap(x,y);
//			for (int i=0;totgroup>=i;i++) {
//				cout<<"i = "<<i<<endl;
//				for (auto j:v[i]) {
//					cout<<" "<<j<<" ";
//				}
//				cout<<endl;
//			}
			_=x/group;
			for (int i=_*group;x>i;i++) {
				if (a[i] > a[x]) {
					ans++;
				}
			}
			for (int i=0;_>i;i++) {
				int val=a[x];
				int pos=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
				ans += (group-pos);
			}
			for (int i=x+1;group*_+group>i;i++) {
				if (a[i] < a[x]) {
					ans++;
				}
			}
			for (int i=_+1;i<=totgroup;i++) {
				int val=a[x];
				int pos=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
				ans += (pos);
			}
//			cout<<"ans = "<<ans<<endl;
			_=y/group;
			for (int i=_*group;y>i;i++) {
				if (a[i] > a[y]) {
//					cout<<"i = "<<i<<" , y=  "<<y<<endl;
//					cout<<"a = "<<a[i]<<" , y="<<a[y]<<endl;
					ans++;
				}
			}
			for (int i=0;_>i;i++) {
				int val=a[y];
				int pos=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
				ans += (group-pos);
			}
//			cout<<"_ = "<<_<<endl;
			for (int i=y+1;group*_+group>i;i++) {
				if (a[i] < a[y]) {
					ans++;
				}
			}
//			cout<<"ans = "<<ans<<endl;
			for (int i=_+1;i<=totgroup;i++) {
				int val=a[y];
				int pos=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
//				cout<<"pos = "<<pos<<" , val = "<<val<<endl;
				ans += (pos);
			}
			if (a[y] >a[x]) ans--;
			printf("%I64d\n",ans);
		}
	}
}