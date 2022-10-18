#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int T,n,m,a[N],c,num,temp[N],q[N],t;
pair<int,int>p[N];
void merge(int begin, int mid, int end)
{
    int i = begin;
    int j = mid + 1;
    int k = begin;
 
    while (i <= mid && j <= end)
    {
        if (a[i] > a[j]) {
            temp[k] = a[j];
            k++;
            j++;
            num += mid - i + 1; //
        } else {
            temp[k] = a[i];
            k++;
            i++;
        }
    }
    while (i <= mid) {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= end) {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (int p = begin; p <= end; p++)
        a[p] = temp[p];
}
 
void mergesort(int begin, int end) { //
    if (begin >= end)
        return;
 
    int mid = (begin + end) / 2;
    mergesort(begin, mid);
    mergesort(mid + 1, end);
    merge(begin, mid, end);
}
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		for(int i=1;i<=n*m;i++)
			cin>>p[i].first,p[i].second=i;
		sort(p+1,p+n*m+1),t=num=0;
		for(int i=1;i<=n*m;i++)
		{
			c=1;
			while(i+c<=n*m&&p[i+c].first==p[i].first)
				c++;
			c=min(c,((i-1)/m+1)*m-i+1);
			for(int j=c;j>=1;j--)
				a[++t]=p[i+j-1].second;
			i+=c-1;
		}
		for(int i=1;i<=n;i++)
			mergesort((i-1)*m+1,i*m);
		cout<<n*m*(m-1)/2-num<<'\n';
	}
	return 0;
}