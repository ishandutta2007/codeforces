#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
typedef int LL;

int main () {
    LL n,k;
    scanf("%d %d",&n,&k);
    LL left = n-k-1;
    LL extra = left - (left/k)*k;
    left /= k;
    LL id=k+2;
    printf("%d\n",(extra>=2?2:extra) + 2*(left+1));
    for (int i=1;k>=i;i++) {
        LL last=i;
        for (int j=1;left>=j;j++) {
            printf("%d %d\n",last,id);
            last=id;
            id++;
        }
        if (extra) {
            printf("%d %d\n",last,id);
            last=id;
            id++;
            extra--;
        }
        printf("%d %d\n",last,k+1);
    }
}