# include <cstdio>
# include <set>
using namespace std;
int dist(int a, int b)
{
    return min((a-b+10)%10, (b-a+10)%10);
}
char t1[1010], t2[1010];
int main()
{
    int n;
    scanf("%d%s%s", &n, t1, t2);
    int res=0;
    for (int i=0; i<n; ++i)
        res+=dist(t1[i], t2[i]);
    printf("%d\n", res);
}