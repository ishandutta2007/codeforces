#include <iostream>
using namespace std;
int main () {
	string s;
	cin >> s;
	int len = s.size();
	//!!! XD 
//	if (len==1) {
//		cout << "First" << endl;
//	}
//	else {  // 
//		if (len%2==0) {  
//			int A=len/2-1,B=len/2;
//			string ans="First";
//			while (A>=0) {
//				if (s[A] != s[B]) {
//					ans = "Second";
//					break;
//				}
//				A--;
//				B++;
//			}
//			cout << ans << endl;
//		}
//		else cout << "First" << endl;
//	}
	int sum[26] = {0};
	int ans=0;
	for (int x=0;len>x;x++) {
		char t = s[x];
		sum[t-'a']++;
		if (sum[t-'a']%2==0) ans--;
		else ans++;
	}
	cout << (ans%2==0&&ans!=0?"Second":"First") << endl;
}