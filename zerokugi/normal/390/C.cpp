#include <iostream>
#include <string>
using namespace std;
#define REP(i,x) for(int i=0;i<(int)(x);i++)

int n, k, w, l, r, data[10][100005] = {0};
main(){
	while(cin >> n >> k >> w){
		string s;
		cin >> s;
		REP(j, k) REP(i, n) data[j][i+1] = ((s[i]-'0')^(i%k==j)) + data[j][i];
		REP(i, w){
			cin >> l >> r;
			cout << data[(l-2+k)%k][r] - data[(l+k-2)%k][l-1] << endl;
		}
	}
	return 0;
}