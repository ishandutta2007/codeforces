#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010;
long long n,d,x;
int a[N]={},b[N]={};
long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
	int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
void work()
{
	map<int,int>m;
	vector<int>v;
	const int s=30;
	for(int i=0;i<n;++i)
	{
		m[a[i]]=i;
		if(b[i])
			v.push_back(i);
		int c=0;
		for(int j=n;j>n-s;--j)
			if(m.count(j) && b[i-m[j]])
			{
				c=j;
				break;
			}
		if(c==0)
			for(vector<int>::iterator it=v.begin();it!=v.end();++it)
				c=max(c,a[i-*it]);
		printf("%d\n",c);
	}
}
int main()
{	
	cin>>n>>d>>x;
	initAB();
	work();
	return 0;
}