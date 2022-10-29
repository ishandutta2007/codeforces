#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main () {
    int n;
    scanf("%d",&n);
    int speed=0;
    vector<int> limit;
    limit.push_back(301);
    int can=0;
    int ans=0;
    while (n--) {
        int t;
        scanf("%d",&t);
        if (t==1) {
            scanf("%d",&speed);
            while (speed > limit.back()) {
                ans++;
                limit.pop_back();
            }
        }
        else if (t==2) {
            ans += can;
            can=0;
        }
        else if (t==3) {
            int x;
            scanf("%d",&x);
            if (speed > x) ans++;
            else limit.push_back(x);
        }
        else if (t==4) {
            can=0;
        }
        else if (t==5) {
            limit.push_back(301);
        }
        else if (t==6){
            can++;
        }
    }
    printf("%d\n",ans);
}