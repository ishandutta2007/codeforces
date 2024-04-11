#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double n,m,k;
    scanf("%lf %lf %lf",&n,&m,&k);
    
    printf("%.0lf\n",4*(sqrt(n*m/k)+sqrt(m*k/n)+sqrt(k*n/m)));
    return 0;
}