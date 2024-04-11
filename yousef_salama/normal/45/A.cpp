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
int index(string a,string b[]){for(int i =0;i<12;i++)if(b[i] == a)return i;}
int main(){
    string s;
    int k;
    cin >> s >> k;
    string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << month[(index(s,month) + k ) % 12] << endl;
}