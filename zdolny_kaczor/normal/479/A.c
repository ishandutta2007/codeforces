#define m(a,b) (a)>(b)?a:b
int a,b,c;main(){scanf("%d%d%d",&a,&b,&c);printf("%d",m(m(a+b+c,a*(b+c)),m((a+b)*c,m(a*b*c,3))));}