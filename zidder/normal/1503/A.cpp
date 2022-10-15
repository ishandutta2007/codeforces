#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n, k=0;
    cin >> n;
    string s, s1="", s2="";
    cin >> s;
    for (int i=0;i<n;++i){
        if (s[i] == '1')
            k++;
        s1 += " ";
        s2 += " ";
    }
    int a1=0, a2=0;
    for (int i=0;i<n;++i){
        if (s[i]=='1'){
            if (a1+a2 == 2 * k){
                a1--;
                a2--;
                s1[i] = s2[i] = ')';
            } else {
                a1++;
                a2++;
                s1[i] = s2[i] = '(';
            }
            k--;
        }
        else{
            if (a1>a2){
                s2[i] = '(';
                s1[i] = ')';
                a1--;
                a2++;
            }else{
                a1++;
                a2--;
                s1[i]='(';
                s2[i]=')';
            }
        }
        if (a1<0 || a2<0)
            break;
    }
    if (a1 == 0 && a2 == 0){
        cout << "YES\n" << s1 << "\n" << s2 << endl;
    } else{cout << "NO" << endl;}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}