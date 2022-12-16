#include<stdio.h>
#include<set>
using namespace std;
set<int>gt;
set<int>::iterator gtw;
int i,n,x;
int main() {
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        scanf("%d",&x);
        while (1) {
            gtw=gt.find(x);
            if (gtw==gt.end()) {
                gt.insert(x); break;
            }
            gt.erase(x); x++;
        }
    }
    gtw=gt.end(); gtw--;
    printf("%d\n",(*gtw)-gt.size()+1);
}