#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

const int N=30;

int out(int a, int b) {
	cout<<"? "<<a<< " "<<b<<endl;
	fflush(stdout);
	int k;cin>>k;
	return k;
}

int main() {
	int left_is_big=-2;
	int need_l=0,need_r=0;
	for (int i = 0; i < N; ++i) {

		const int place=N-i-1;
		if (left_is_big == -2) {
			int answer=out(need_l,need_r);
			left_is_big=answer;
		}

		if (left_is_big !=0) {
			int answer=out(need_l+(1<<place)-1,need_r+(1<<place)-1);
			if (answer == left_is_big) {
				if(left_is_big==1)need_l+=(1<<place);
				else need_r+=(1<<place);

				left_is_big=-2;
			}
			else if (answer == 0) {
				assert(false);
			}
			else{
				int nanswer=out(need_l+(1<<place),need_r);
				if (nanswer == -1) {
					need_l+=(1<<place);
					need_r+=(1<<place);
				}
				else if (nanswer == 0) {
					assert(false);
				}
				else {
					
				}
			}
		}
		else {
			int nanswer=out(need_l+(1<<place),need_r);
			if (nanswer == -1) {
				need_l+=(1<<place);
				need_r+=(1<<place);
			}
			else if (nanswer == 0) {

			}
			else {

			}
		}
	}
	cout << "! " << need_l << " " << need_r << endl;

	return 0;
}