#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=0;i<k;i++){
        bool z=false, o=false;
        for (int j=i;j<n;j+=k){
            if (s[j] == '1'){
                o=true;
            }
            if (s[j] == '0'){
                z=true;
            }
        }
        if (o && z){
            cout << "NO" << endl;
            return;
        }
        if (o||z){
            char c = o?'1':'0';
            for (int j=i;j<n;j+=k)
                s[j] = c;
        }
    }
    int ones = 0, zeros=0;
    for(int i=0;i<k;++i){
        if (s[i]=='1')
            ones++;
        if (s[i]=='0')
            zeros++;
    }
    if (ones > k/2 || zeros > k/2){
        cout <<"NO"<<endl;
        return;
    }
    cout << "YES" <<endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}