#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;

int a[MAX_N];
pii b[MAX_N];
int val[MAX_N];

int ans1[MAX_N];
int ans2[MAX_N];
vector<int> v1[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		map<int,int> mp;
		set<int> st;
		vector<int> v;
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			v.push_back(a[x]);
		}
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end()) - v.begin());
		for (int x=1;n>=x;x++) {
			int tmp=a[x];
			int l=lower_bound(v.begin(),v.end(),tmp) - v.begin() + 1;
			val[l]=a[x];
			a[x]=l;
			mp[val[l]]=l;
		}
		for (int x=1;n>=x;x++) {
			if (st.find(val[a[x]]) != st.end()) {
				v1[a[x]].push_back(x);
			}
			else {
				st.insert(val[a[x] ]);
				v1[a[x]].push_back(x);
			}
		}
		for (int x=1;m>=x;x++) {
			scanf("%d",&b[x].first);
			b[x].second=x;
		}
		sort(b+1,b+m+1);
		int u=0,c=0; //u-->how many /2 , c-->how many can use
		for (int x=1;m>=x;x++) {
			int tmp=b[x].first;
			int tmpu=0;
			while (tmp>0) {
				if (st.find(tmp) != st.end()) {
					int q=mp[tmp];
//					cout<<"tmp = "<<tmp<<" , q = "<<q<<endl;
					int sz=v1[q].size();
					u += tmpu;
					c ++;
					ans1[b[x].second] = tmpu;
					ans2[v1[q][sz-1]] =b[x].second;
					v1[q].pop_back();
					if (sz != 1) ;
					else {
						st.erase(tmp);
						v1[q].clear();
					}
					break;
				}
				else {
					if (tmp==1) break;
					else tmp=(tmp+1)/2;
					tmpu++;
				}
			}
		}
		printf("%d %d\n",c,u);
		for (int x=1;m>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",ans1[x]);
		}
		puts("");
		for (int x=1;n>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",ans2[x]);
		}
		puts("");
	}
}