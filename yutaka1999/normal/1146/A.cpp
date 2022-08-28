#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#define SIZE 55

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	int a=0;
	for(int i=0;i<n;i++) if(str[i]=='a') a++;
	printf("%d\n",min(n,2*a-1));
	return 0;
}