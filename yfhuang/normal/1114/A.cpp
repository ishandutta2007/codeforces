#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int x, y, z;
    int a, b, c;
    while(cin >> x >> y >> z){
        cin >> a >> b >> c;
        bool flag = true;
        if(a < x)
            flag = false;
        else{
            a -= x;
            int c1 = min(a, y);
            a -= c1;
            y -= c1;
            if(b < y)
                flag = false;
            else{
                b -= y;
                if(a + b + c < z)
                    flag = false;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}