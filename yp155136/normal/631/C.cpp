#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <deque>
using namespace std;

const int MAX_N = 200003;
int a[MAX_N];
int tmp[MAX_N];

struct Query {
	int type;
	int r;
} query[MAX_N];

bool operator< (const Query& q1, const Query& q2) {
	return q1.r < q2.r;
}

bool operator> (const Query& q1, const Query& q2) {
	return q1.r > q2.r;
}

bool operator== (const Query& q1, const Query& q2) {
	return q1.r == q2.r;
}

bool operator<= (const Query& q1, const Query& q2) {
	return q1.r <= q2.r;
}

bool operator>= (const Query& q1, const Query& q2) {
	return q1.r >= q2.r;
}


int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for(int x=0;n>x;x++) {
			scanf("%d",&a[x]);
			tmp[x]=a[x];
		}
		
		deque<Query> deq;
		for (int x=0;m>=x;x++) {
			Query tmp;
			if (x!=m) scanf("%d %d",&tmp.type,&tmp.r);
			else if (x==m) tmp.r=0,tmp.type=1;
			if (deq.empty()==true) {
				deq.push_back(tmp);
			}
			else {
				while (deq.empty()==false && deq.back() <= tmp) {
					deq.pop_back();
				}
				deq.push_back(tmp);
			}
		}
		int len=0;
		while (deq.empty()==false) {
			query[len++] = deq.front();
			deq.pop_front();
		}
		int R = query[0].r;
		sort(a,a+R);
		int st=0,ed=R-1;
		int ist=0,ied=R-1;
//		cout<<"st = "<<st<<" , ed = "<<ed<<endl;
		for (int x=0;len-1>x;x++) {
//			cout<<"query["<<x<<"].r = " <<query[x].r <<endl;
//			cout << "st = "<<st<<" , ed = "<<ed<<endl;
			int d = query[x].r - query[x+1].r;
			if (query[x].type==1) {
				int id=ied-d+1;
//				cout<<ed-d+1<<" to "<<ed<<endl;
				for (int x=ed-d+1;ed>=x;x++) {
//					cout<<"tmp["<<id<<"] = a["<<x<<"]\n";
					tmp[id++]=a[x];
				}
				ed=ed-d;
				ied=ied-d;
			}
			else {
				int id=ied-d+1;
//				cout<<st << " to "<< st+d-1 <<endl;
				for (int x=st+d-1;x>=st;x--) {
//					cout<<"tmp["<<id<<"] = a["<<x<<"]\n";
					tmp[id++]=a[x];
				}
				st=st+d;
				ied=ied-d;
			}
//			for (int x=0;n>x;x++) cout<<tmp[x]<<' ';
//			cout<<endl;
		}
		for (int x=0;R>x;x++) a[x]=tmp[x];
		for (int x=0;n>x;x++) {
			printf("%d",a[x]);
			if (x!=n-1) printf(" ");
		}
		puts("");
	}
}