#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <cassert>
#include <cmath>

#define mp make_pair
#define point pair<int, int> 
#define px first
#define py second
#define INF 1000000000
#define EPS 1e-8
#define loop(i, x) for(int i = 0; i < (x); i++)
#define rep(x) for (int COUNTER = 0; COUNTER < (x); COUNTER++)

using namespace std;

int main()
{
    double A, D;
    int N;
    scanf("%lf%lf%d", &A, &D, &N);
    
    double pos = D;
    for (int i = 1; i <= N; i++, pos += D)
    {
        pos = fmod(pos, A*4);
        
        double x, y;
        if (pos <= A)
        {
            x = pos;
            y = 0;
        }
        else if (pos <= A*2)
        {
            x = A;
            y = pos - A;
        }
        else if (pos <= A*3)
        {
            x = A*3 - pos;
            y = A;
        }
        else
        {
            x = 0;
            y = A*4 - pos;
        }
        
        printf("%.10lf %.10lf\n", x, y);
    }
}