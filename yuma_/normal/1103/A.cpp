#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



int main()
{
	string st;cin>>st;
	bool ver_flag=false;
	bool hor_flag=false;
	for (int i = 0; i < st.size(); ++i) {
		if (st[i] == '0') {
			if (ver_flag == false) {
				cout<<1<<" "<<1<<endl;
			}
			else {
				cout<<3<<" "<<1<<endl;
			}
			ver_flag=!ver_flag;
		}
		else {
			if (hor_flag == false) {
				cout<<4<<" "<<3<<endl;
			}
			else {
				cout<<4<<" "<<1<<endl;
			}
			hor_flag=!hor_flag;
		}
	}
	return 0;
}