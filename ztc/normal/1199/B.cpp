#include<stdio.h>
double h,l;
int main(){
    scanf("%lf%lf",&h,&l);
    printf("%.8lf",(l*l-h*h)/h/2);
}