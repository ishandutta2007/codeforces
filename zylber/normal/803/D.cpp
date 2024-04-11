#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	int top = 1000000, bot = 0;
	
	int ss = s.size();
	vector<int> breaks(1,-1);
	for(int i=0; i<ss; i++) {
		if(s[i] == '-' || s[i] == ' ') breaks.push_back(i);
	}
	breaks.push_back(ss-1);
	int bs = breaks.size();
	
	while(top-bot > 1) {
		int mid = (top+bot)/2;
		int anda = 1, lineas = 1, iact = -1;
		for(int i =1; i<bs; i++) {
			//cout << breaks[i] << " " << iact << endl;
			if(breaks[i] - iact > mid) {
				lineas++;
				iact = breaks[i-1];
				if(breaks[i]-breaks[i-1] > mid) anda = 0;
			}
		}
		if(anda && lineas <= k) {
			top = mid;
		} 
		else
		{
			bot = mid;
		}
	}
	cout << top << endl;
}