#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <utility>
#include <set>
#include <cassert>
using namespace std;

#define int long long
typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;

int a[2*MAX_N],b[2*MAX_N],v[2*MAX_N];
int n,w,k;
bool used[2*MAX_N];

set<pii> st;
set<pii> st2;
LL sum;
LL val;

void add(int id) {
//	cout<<"add id = "<<id<<"  ";
	val += v[id];
	if (st.size()<w) {
//		cout<<"in1\n";
//		cout<<"add ("<<a[id]<<","<<id<<")\n";
		st.insert(make_pair(a[id],id));
		sum += b[id];
	}
	else if ((*st.begin()).first <= a[id]) {
//		cout<<"in2\n";
//		cout<<"add ("<<a[id]<<","<<id<<")\n";
		pii tmp=*st.begin();
//		cout<<"tmp = ("<<tmp.first<<","<<tmp.second<<")\n";
		st.erase((st.begin()));
		st.insert(make_pair(a[id],id));
		sum += (a[tmp.second]-b[tmp.second]);
		sum += b[id];
		st2.insert(tmp);
	}
	else {
//		cout<<"in3\n";
		sum += a[id];
//		cout<<"add ("<<a[id]<<","<<id<<")\n";
		st2.insert(make_pair(a[id],id));
	}
}

void deleted(int id) {
	val -= v[id];
	pii tmp=make_pair(a[id],id);
	if (st2.find(tmp) !=st2.end()) {
//		cout<<"id = "<<id<<" in2\n";
		st2.erase(st2.find(tmp));
		sum -= a[id];
	}
	else if (st.find(tmp) != st.end()) {
//		cout<<"id = "<<id<<" in1\n";
		st.erase(st.find(tmp));
		sum -= b[id];
		if (st2.size()>0) {
			pii temp=*(--(st2.end()));
//			cout<<"temp = ("<<temp.first<<","<<temp.second<<") \n";
			st2.erase(temp);
			sum += (b[temp.second]-a[temp.second]);
			st.insert(temp);
		}
	}
	else {
		assert(0);
	}
}

main () {
	while (scanf("%I64d %I64d %I64d",&n,&w,&k) != EOF) {
		st.clear();
		st2.clear();
		sum=val=0;
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&v[i]);
		}
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
			b[i] = a[i]/2 + (a[i]&1);
			//cout<<"i = "<<i<<" , a = "<<a[i]<<" , b = "<<b[i]<<endl;
		}
		for (int i=1;n>=i;i++) {
			a[i+n]=a[i];
			b[i+n]=b[i];
			v[i+n]=v[i];
		}
		int R=1;
		LL ans=-1;
		memset(used,0,sizeof(used));
		for (int L=1;n>=L;L++) {
			if (used[L-1]) deleted(L-1);
			if (R<=L) {
				R=L+1;
				add(L);
				used[L]=1;
			}
			while (sum <= k) {
				if (used[n] &&sum <= k) {
					ans = max(ans,val);
					printf("%I64d\n",ans);
					return 0;				
				}
				add(R);
				used[R]=1;
				R++;
				if (used[n] &&sum <= k) {
					ans = max(ans,val);
					printf("%I64d\n",ans);	
					return 0;				
				}
			}
			if (sum>k) {
				R--;
				deleted(R);
				used[R]=0;
			}
//			cout<<"L = "<<L<<" , R = "<<R<< " ,st.size() = "<<st.size()<<" , st2 = "<<st2.size()<<endl;
			//assert(st.size()+st2.size()==R-L);
//			cout<<"\nst2 :\n";
//			for (auto i:st2) {
//				cout<<"i = ("<<i.first<<","<<i.second<<") \n";
//			}
//			cout<<"\nst :\n";
//			for (auto i:st) {
//				cout<<"i = ("<<i.first<<","<<i.second<<") \n";
//			}
//			cout<<"\n";
			ans = max(ans,val);
		}
		printf("%I64d\n",ans);
	}
}