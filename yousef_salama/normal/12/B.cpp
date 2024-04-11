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
    string n,m;
    cin >> n >> m;
    char a[] = {'1','2','3','4','5','6','7','8','9'};
    string s = n;
    int p = 0;
    for(int i =0;i<9;i++){
        for(int j =0;j<n.size();j++){
            if(s[j] == a[i])swap(s[p++],s[j]);
        }
    }
    p = 1;
    for(int i =2;i<n.size();i++)if(s[i] == '0'){
        p++;
        int p2 = i;
        for(int j = i-1;j >= p-1;j--){
            swap(s[p2--],s[j]);
        }
    }
    cout << (s == m?"OK":"WRONG_ANSWER") << endl;
}