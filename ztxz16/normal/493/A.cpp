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

char s1[105], s2[105], str[105], type[105];
int tt, number, tag1[105], tag2[105];
int n;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tt);
        scanf("%s", str);
        scanf("%d", &number);
        scanf("%s", type);
        if (str[0] == 'h') {
            if (tag1[number] == 2) {
                continue;
            } else if (tag1[number] == 1 || type[0] == 'r') {
                printf("%s %d %d\n", s1, number, tt);
                tag1[number] = 2;
            } else {
                tag1[number] = 1;
            }
        } else {
            if (tag2[number] == 2) {
                continue;
            } else if (tag2[number] == 1 || type[0] == 'r') {
                printf("%s %d %d\n", s2, number, tt);
                tag2[number] = 2;
            } else {
                tag2[number] = 1;
            }
        }
    }
    
    return 0;
}