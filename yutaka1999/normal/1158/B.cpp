#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <functional>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
    if(k==1)
    {
        for(int i=0;i<n-1;i++) printf("1");
        printf("0");
        puts("");
        return 0;
    }
    int t=(n-k)/2+1;
    if(n%t==0)
    {
        for(int i=0;i<n;i++)
        {
            if(i%t==0) printf("1");
            else printf("0");
        }puts("");
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(i%t<n%t) printf("1");
            else printf("0");
        }puts("");
    }
	return 0;
}