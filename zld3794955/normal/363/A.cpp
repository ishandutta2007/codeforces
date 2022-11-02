#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n;
int main()
{   
    scanf("%d",&n);
    if(n==0)
        printf("O-|-OOOO\n");
    while(n)
    {
        int t=n%10;
        n/=10;
        if(t==0)
            printf("O-|-OOOO\n");
        if(t==1)
            printf("O-|O-OOO\n");
        if(t==2)
            printf("O-|OO-OO\n");
        if(t==3)
            printf("O-|OOO-O\n");
        if(t==4)
            printf("O-|OOOO-\n");
        if(t==5)
            printf("-O|-OOOO\n");
        if(t==6)
            printf("-O|O-OOO\n");
        if(t==7)
            printf("-O|OO-OO\n");
        if(t==8)
            printf("-O|OOO-O\n");
        if(t==9)
            printf("-O|OOOO-\n");
    }
    return 0;
}