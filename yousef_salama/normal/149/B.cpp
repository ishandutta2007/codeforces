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
#include <string.h>
using namespace std;
string conv(int decimal, int base){
    if(decimal == 0) return "0";
    string NUMS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    do{
        result.push_back(NUMS[decimal%base]);
        decimal /= base;
    }while(decimal != 0);
    return string(result.rbegin(), result.rend());
}
int num(char c){
    if(isalpha(c))return c - 'A' + 10;
    else return c - '0';
}
string c, a, b;
int main(){
    cin >> c;
    int i;
    for(i = 0; i < c.size(); i++){
        if(c[i] == ':')break;
        else a += c[i];
    }
    i++;
    for( ; i < c.size(); i++)
        b += c[i];
    long long ai = 0, bi = 0;
    bool empty = 1;
    bool flag1, flag2;
    vector <int> print;
    for(int base = 2; base < 100; base++){
        flag1 = 0;
        for(int i = 0; i < a.size(); i++)
            if(num(a[i]) >= base)flag1 = 1;
        if(flag1)continue;
        flag2 = 0;
        for(int i = 0; i < b.size(); i++)
            if(num(b[i]) >= base)flag2 = 1;
        if(flag2)continue;
        ai = 0; bi = 0;
        long long shift = 1;
        for(int i = a.size() - 1; i >= 0; i--){
            ai += num(a[i]) * shift;
            shift *= base;
        }
        shift = 1;
        for(int i = b.size() - 1; i >= 0; i--){
            bi += num(b[i]) * shift;
            shift *= base;
        }
        if(ai < 24 && bi < 60){
            print.push_back(base);
        }
        else break;
    }
    if(print.size() >= 60)printf("-1\n");
    else if(print.size() == 0)printf("0\n");
    else{
        for(int i = 0; i < print.size(); i++)
            cout << print[i] << ' ';
        cout << endl;
    }
    return 0;
}