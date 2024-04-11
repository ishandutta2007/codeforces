#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 150005

using namespace std;

int A[SIZE];
int n;

int check(int i)
{
	if(i%2==0&&A[i]>=A[i+1]) return 1;
	else if(i%2==1&&A[i]<=A[i+1]) return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	vector <int> vec;
	for(int i=0;i<n;i++)
	{
		if(check(i)==1)
		{
			vec.push_back(i);
			vec.push_back(i+1);
			break;
		}
	}
	int ret=0;
	for(int i=0;i<vec.size();i++)
	{
		int v=vec[i];
		int cnt=0;
		for(int j=0;j+1<n;j++) cnt+=check(j);
		for(int j=0;j<n;j++)
		{
			if(j==v) continue;
			if(i==0&&j==vec[1]) continue;
			int bef=cnt;
			if(j-1!=v&&j>0) cnt-=check(j-1);
			cnt-=check(j);
			if(v-1!=j&&v>0) cnt-=check(v-1);
			cnt-=check(v);
			swap(A[j],A[v]);
			if(j-1!=v&&j>0) cnt+=check(j-1);
			cnt+=check(j);
			if(v-1!=j&&v>0) cnt+=check(v-1);
			cnt+=check(v);
			if(cnt==0) ret++;
			swap(A[j],A[v]);
			cnt=bef;
		}
	}
	printf("%d\n",ret);
	return 0;
}