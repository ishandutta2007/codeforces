#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
using namespace std;
int a, x, y;
int main(){
    scanf("%d %d %d", &a, &x, &y);
    int i = y / a + 1;
    if(i == 1){
        if(-a < x * 2 && x * 2 < a && y != 0)printf("1\n");
        else printf("-1\n");
    }
    else{
        int num = 2;
        for(int j = 2; j < i; j++, num += !(j % 2) + 1);
        if(i % 2 == 0){
            if(-a < x * 2 && x * 2 < a && y != a * (i - 1))printf("%d\n", num);
            else printf("-1\n");
        }
        else{
            if(-a < x && x < a && y != a * (i - 1) && x != 0){
                if(-a < x && x < 0)
                    printf("%d\n", num);
                else printf("%d\n", num + 1);
            }
            else printf("-1\n");
        }
    }
    return 0;
}