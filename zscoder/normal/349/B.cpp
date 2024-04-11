#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 100050
struct node{
    int p,i;
}pri[14];
bool cmp(node a,node b){
    if(a.p!=b.p)return a.p<b.p;
    else return a.i>b.i;
}
int main()
{
    int v,i;
    while(scanf("%d",&v)!=EOF){
        for(i=1;i<=9;i++)
        scanf("%d",&pri[i].p),pri[i].i=i;
        sort(pri+1,pri+10,cmp);
        int n=v/pri[1].p;
        if(n==0)printf("-1\n");
        else {
            int res=v-n*pri[1].p,maxx=pri[1].i,kk=0;
            while(1){
                int temp=-1;maxx=pri[1].i;
                for(i=1;i<=9;i++){
                    if(res+pri[1].p>=pri[i].p&&maxx<pri[i].i){
                        temp=i;
                        maxx=pri[i].i;
                    }

                }
                if(temp==-1)break;
                res=res-pri[temp].p+pri[1].p;
                printf("%d",maxx);kk++;
            }
            for(;kk<n;kk++)printf("%d",pri[1].i);
            printf("\n");
        }
    }
    return 0;
}