#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n;
typedef long long int64;
const int MAX_N = 50;
int64 answer[MAX_N + 1];
int main() {
	answer[2] = 3LL;
	answer[3] = 5LL;
	answer[4] = 25LL;
	answer[5] = 59LL;
	answer[6] = 97LL;
	answer[7] = 239LL;
	answer[8] = 95LL;
	answer[9] = 119LL;
	answer[10] = 507LL;
	answer[11] = 3487LL;
	answer[12] = 7333LL;
	answer[13] = 4313LL;
	answer[14] = 9541LL;
	answer[15] = 32057LL;
	answer[16] = 53035LL;
	answer[17] = 189143LL;
	answer[18] = 486961LL;
	answer[19] = 602161LL;
	answer[20] = 692181LL;
	answer[21] = 3749685LL;
	answer[22] = 5666119LL;
	answer[23] = 2612725LL;
	answer[24] = 28939211LL;
	answer[25] = 48906931LL;
	answer[26] = 130097631LL;
	answer[27] = 223561211LL;
	answer[28] = 339419171LL;
	answer[29] = 478475725LL;
	answer[30] = 1513517851LL;
	answer[31] = 4151082213LL;
	answer[32] = 3067098099LL;
	answer[33] = 815774593LL;
	answer[34] = 30919633783LL;
	answer[35] = 6639234397LL;
	answer[36] = 63406103045LL;
	answer[37] = 196974070485LL;
	answer[38] = 160715692415LL;
	answer[39] = 649067163679LL;
	answer[40] = 1968703023731LL;
	answer[41] = 4199885479225LL;
	answer[42] = 5260526710483LL;
	answer[43] = 11350565584815LL;
	answer[44] = 18000475705097LL;
	answer[45] = 30474977225109LL;
	answer[46] = 13504636890057LL;
	answer[47] = 33940824593261LL;
	answer[48] = 20636564487877LL;
	answer[49] = 18707714161455LL;
	answer[50] = 20540225290239LL;
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		if (i > 0)
			cout << " ";
		cout << ((answer[k] >> (k - 1 - i)) & 1);
	}
	cout << endl;
	for (int i = 0; i < k; ++i) {
		if (i > 0)
			cout << " ";
		cout << 1;
	}
	cout << endl;
	return 0;
}