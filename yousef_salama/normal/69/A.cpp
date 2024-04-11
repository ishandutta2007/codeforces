#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <ctype.h>
#include <math.h>

using namespace std;
int main (){
    int n , z=0 ,x=0 ,y=0,za,xa,ya;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> xa >> ya >> za;
        z += za;
        x += xa;
        y += ya;
    }
    if (z == 0 && x == 0 && y == 0)cout << "YES";
    else cout << "NO";
}