#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main()
{
	int s,v1,v2,t1,t2;
	int s1,s2;
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	s1=2*t1+s*v1;
	s2=2*t2+s*v2;
	if(s1<s2)
		printf("First\n");
	else if(s2<s1)
		printf("Second\n");
	else
		printf("Friendship\n");
	return 0;
}