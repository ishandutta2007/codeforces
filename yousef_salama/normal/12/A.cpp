#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main(){
    string a[3];
    string s;
    for(int i =0;i<3;i++) {
        cin >> s;
        a[i] = s;
    }
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            if(a[i][j] != a[2-i][2-j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}