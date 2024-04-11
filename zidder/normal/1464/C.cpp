#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    long long n, T;
    cin >> n >> T;
    string s;
    cin >> s;
    T -= (1<<(s[--n] - 'a'));
    T += (1<<(s[--n] - 'a'));
    int a[64]={0};
    for (int i=0;i<n;++i){
        a[s[i]-'a']++;
    }
    bool r1 = false, r0 = false;
    T = abs(T);
    bool no = false;
    for (int i=0;i<63;++i){
        if ((T&1)){
            if ((a[i]&1) == 0){
                if (!r1)
                    no = true;
                a[i]--;
                if (a[i] == -1){
                    r0 = true;
                    r1 = true;
                }
                else
                    r0 = false;
            }
            else{
                if (r0)
                    no = true;
            }
        }
        else{
            if (a[i] & 1){
                if (!r1)
                    no = true;
                a[i]--;
            }
            else
                if (r0)
                    no = true;
            r0 = false;
        }
        if (a[i])
            r1 = true;
        else
            r1 =false;
        a[i+1] += a[i]/2;
        T /= 2;
    }
    if (no)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}