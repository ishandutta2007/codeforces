#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

long long l, r;
int n;

int main() {
    scanf("%d", &n);
    while (n--) {
        cin >> l >> r;
        long long ans = 0;
        for (int i = 62; i >= 0; i--) {
            long long now = (1LL << i);
            if ((l & now) && (r & now)) {
                ans += now;
            } else if (!(l & now) && !(r & now)) {
                continue;
            } else {
                for (int j = i; j >= 0; j--) {
                    ans += (1LL << j);
                }
                
                if (ans > r) {
                    ans -= (1LL << i);
                }
                
                break;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}