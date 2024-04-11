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
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
long long d;
int Max = 0;
string p;
long long calc(int nines){
    if(nines <= Max){
        string s = "";
        for(int i = 0; i < nines; i++)
            s += "9";
        for(int i = p.size() - nines - 1; i >= 0; i--){
            s = p.substr(i, 1) + s;
        }
        return atoll(s.c_str());
    }else{
        if(p.size() == nines)return -1;

        string s = "";
        for(int i = 0; i < nines; i++)
            s += "9";
        p[p.size() - nines - 1]--;
        s = p.substr(p.size() - nines - 1, 1) + s;
        p[p.size() - nines - 1]++;
        for(int i = p.size() - nines - 2; i >= 0; i--)
            s = p.substr(i, 1) + s;
        
        return atoll(s.c_str());
    }
}
int main(){
    cin >> p >> d;
    while(p.size() > Max){
        if(p[p.size() - Max - 1] != '9')break;
        Max++;
    }

    for(int nines = p.size(); nines >= 0; nines--){
        long long x = calc(nines);
        if(x != -1 && (atoll(p.c_str()) - x) <= d){
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}