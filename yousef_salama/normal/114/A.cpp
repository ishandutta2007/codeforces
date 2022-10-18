    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <cstring>
    #include <string>
    #include <cctype>
    #include <stack>
    #include <queue>
    #include <list>
    #include <vector>
    #include <map>
    #include <sstream>
    #include <bitset>
    #include <utility>
    #include <set>
    #include <cmath>
    #define pi acos(-1.0)
    #define N 1000000
    #define min(x,y) ((x) < (y) ? (x) : (y))
    #define max(x,y) ((x) > (y) ? (x) : (y))
     
    using namespace std;
     
    int main() {
        long long k,l,importance=0,temp;
        bool flag=true;
        cin >> k >> l;
        temp=k;
        while(1) {
            if(k==l)  break;
            k*=temp;
            importance++;
            if(k>l) {
                flag=false;
                break;
            }
        }
        if (flag==false) printf("NO");
        else {
            puts("YES");
            cout << importance << endl;
        }
     
        return 0;
    }