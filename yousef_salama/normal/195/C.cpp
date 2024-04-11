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
int n, cnt = 0, expI;
string s, cur = "$$$$$$";
stack <int> x;
bool found = false;
int main(){
    cin >> n;
    getline(cin, s);
    for(int itr = 0; itr < n; itr++){
        getline(cin, s);

        int i = 0;
        while(i < s.size() && s[i] == ' ')i++;

        if(i + 2 < s.size() && s[i] == 't' && s[i + 1] == 'r' && s[i + 2] == 'y')
            x.push(itr);
        if(i + 4 < s.size() && s[i] == 't' && s[i + 1] == 'h' && s[i + 2] == 'r' && s[i + 3] == 'o' &&
                s[i + 4] == 'w'){
            i += 5;
            while(i < s.size() && (s[i] == ' ' || s[i] == '('))i++;

            string exp = "";
            while(i < s.size() && (s[i] != ' ' && s[i] != ')')){
                exp += s[i];
                i++;
            }
            expI = itr;
            cur = exp;
        }
        if(i + 4 < s.size() && s[i] == 'c' && s[i + 1] == 'a' && s[i + 2] == 't' && s[i + 3] == 'c' &&
                s[i + 4] == 'h'){
            i += 5;
            while(i < s.size() && (s[i] == ' ' || s[i] == '('))i++;

            string exp = "";
            while(i < s.size() && (s[i] != ',' && s[i] != ' ')){
                exp += s[i];
                i++;
            }
            while(i < s.size() && s[i] != '"')i++;
            i++;

            string message = "";
            while(i < s.size() && s[i] != '"'){
                message += s[i];
                i++;
            }
            if(cur == exp && x.top() < expI && !found){
                cout << message << endl;
                found = true;
            }
            x.pop();
        }
    }
    if(!found)cout << "Unhandled Exception" << endl;
    return 0;
}