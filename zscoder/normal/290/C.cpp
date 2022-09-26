#include<cstdio>

int main(){
    int tux;
    scanf("%d",&tux);
    int foo=0,bar=0,baz=0,quz=1;
    for(int i=0;i<tux;i++){
        int pur;
        scanf("%d",&pur);
        foo+=pur;
        bar++;
        if(foo*quz>=bar*baz){
            baz=foo;
            quz=bar;
        }
    }
    printf("%.6lf\n",(double)baz/quz);

    return 0;
}