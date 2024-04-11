#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	int H;cin>>H;
	vector<int>as(H+1);
	for (int i = 0; i <= H; ++i) {
		int a;cin>>a;
		as[i]=a;
	}

	int num=accumulate(as.begin(),as.end(),0);

	vector<int>ans1(num),ans2(num);
	bool flag=false;
	for (int i = 0; i < H; ++i) {
		if (as[i] >= 2 && as[i + 1] >= 2) {
			flag=true;
		}
	}

	if (flag) {
		cout<<"ambiguous"<<endl;
		int id=0;
		int pre_id=-1;

		bool aflag=true;
		for (int i = 0; i <= H; ++i) {
			if (i == 0) {
				assert(as[i]==1);
				ans1[id]=0;
				ans2[id]=0;
				id++;
				pre_id=0;
			}
			else {

				for (int k = id; k < id + as[i]; ++k) {
					ans1[k]=pre_id+1;
					ans2[k]=pre_id+1;
				}
				if (as[i] >= 2 && as[i - 1] >= 2) {
					if (aflag) {

						ans1[id] = pre_id+1;
						ans2[id] = pre_id;
						aflag=false;
					}
				}
				id += as[i];
				pre_id+=as[i];
			}
			
		}
		for (int i = 0; i < num; ++i) {
			cout<<ans1[i];
			if(i==num-1)cout<<endl;
			else cout<<" ";
		}
		for (int i = 0; i < num; ++i) {
			cout << ans2[i];
			if (i == num - 1)cout << endl;
			else cout << " ";
		}
	}
	else {
		cout<<"perfect"<<endl;
	}
	return 0;
}