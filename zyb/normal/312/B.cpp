#include<cstdio>
using namespace std;

int a,b,c,d;
double x,ans;

int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    x=(double) a/b;ans+=x;
    for (;;){
        x=(double)x*(b-a)*(d-c)/b/d;
        ans+=x;
        if (x<1e-9) break;
    }
    printf("%.10lf",ans);
}