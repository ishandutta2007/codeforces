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
    int n = 0,out = 0;
//    freopen("a.in","r",stdin);
    string s;
    while(getline(cin,s)){
        if(s[0] == '+')n++;
        else if(s[0] == '-')n--;
        else out += n * (s.size() - s.find(':') - 1);
    }
    cout << out << endl;
}