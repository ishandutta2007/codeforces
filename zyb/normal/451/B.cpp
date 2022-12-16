#include<stdio.h>
#include<algorithm>
#define maxn 100005

using namespace std;
int a[maxn];
int main()
{
    int n, i, j;
    while(scanf("%d", &n) != EOF){
        int x = 1, y = 1;
        for(i = 1; i <= n; i++)
            scanf("%d",&a[i]);

        for(i = 1; i < n; i++)
        if(a[i] > a[i+1]){
            x = i; break;
        }
        for(i = n; i >= 1; i--)
        if(a[i] < a[i-1]){
            y = i; break;
        }

        reverse(a+x, a+y+1);
        int flag=0;
        for(i = 1; i < n; i++)
            if(a[i] > a[i+1]){
                flag = 1; break;
            }
        if(flag)
            printf("no\n");
        else
            printf("yes\n%d %d\n", x, y);
    }
    return 0;
}