#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int c=0;
    int ans=0;
    while (n--) {
        int x;
        scanf("%d",&x);
        if (x==1) {
            if (a) a--;
            else if (b) b--,c++;
            else if (c) c--;
            else ans++;
        }
        else if (x==2) {
            if (b) b--;
            else ans+=2;
        }
    }
    printf("%d\n",ans);
}