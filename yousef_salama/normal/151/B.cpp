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
int n, s, MaxT = 0, MaxP = 0, MaxG = 0;
string name, num;
vector <string> taxis, pizzas, girls;
bool isTaxi(string a){
    if(a[0] == a[1] && a[1] == a[3] && a[3] == a[4] && a[4] == a[6] && a[6] == a[7])return true;
    return false;
}
bool isPizza(string a){
    if(a[0] > a[1] && a[1] > a[3] && a[3] > a[4] && a[4] > a[6] && a[6] > a[7])return true;
    return false;
}
int main(){
    cin >> n;
    while(n--){
        cin >> s >> name;
        int t = 0, p = 0, g = 0;
        while(s--){
            cin >> num;
            if(isTaxi(num))t++;
            else if(isPizza(num))p++;
            else g++;
        }
        if(t > MaxT){
            taxis.clear();
            taxis.push_back(name);
            MaxT = t;
        }else if(t == MaxT)taxis.push_back(name);
        if(p > MaxP){
            pizzas.clear();
            pizzas.push_back(name);
            MaxP = p;
        }else if(p == MaxP)pizzas.push_back(name);
        if(g > MaxG){
            girls.clear();
            girls.push_back(name);
            MaxG = g;
        }else if(g == MaxG)girls.push_back(name);
    }
    cout << "If you want to call a taxi, you should call: ";
    for(int i = 0; i < taxis.size(); i++){
        if(i != 0)cout << ", ";
        cout << taxis[i];
    }
    cout << '.' << endl;
    cout << "If you want to order a pizza, you should call: ";
    for(int i = 0; i < pizzas.size(); i++){
        if(i != 0)cout << ", ";
        cout << pizzas[i];
    }
    cout << '.' << endl;
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for(int i = 0; i < girls.size(); i++){
        if(i != 0)cout << ", ";
        cout << girls[i];
    }
    cout << '.' << endl;
    return 0;
}