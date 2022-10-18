#include<iostream>
using namespace std;
const int N=1e5;
bool t;
int n,a[N],A[N];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(a[0]<a[1])
		A[0]=1;
	else if(a[0]>a[1])
		A[0]=5;
	else
		A[0]=3;
	for(int i=1;i<n-1;i++)
	{
		if(a[i-1]<a[i]&&a[i]<=a[i+1])
			A[i]=A[i-1]+1;
		else if(a[i-1]<=a[i]&&a[i]>a[i+1])
			A[i]=5;
		else if(a[i-1]>=a[i]&&a[i]<a[i+1])
			A[i]=1;
		else if(a[i-1]>a[i]&&a[i]>=a[i+1])
			A[i]=A[i-1]-1;
		else
			A[i]=3;
		if(A[i]==A[i-1])
			if(A[i]<4)
				A[i]++;
			else
				A[i]--;
	}
	if(a[n-2]<a[n-1])
		A[n-1]=A[n-2]+1;
	else if(a[n-2]>a[n-1])
		A[n-1]=A[n-2]-1;
	else if(A[n-2]<5)
		A[n-1]=A[n-2]+1;
	else
		A[n-1]=A[n-2]-1;
	for(int i=1;i<n;i++)
		if(A[i-1]<1||A[i-1]>5)
			t=true;
		else if(a[i-1]<a[i]&&A[i-1]>=A[i])
			t=true;
		else if(a[i-1]>a[i]&&A[i-1]<=A[i])
			t=true;
		else if(a[i-1]==a[i]&&A[i-1]==A[i])
			t=true;
	if(t)
		cout<<-1;
	else
		for(int i=0;i<n;i++)
			cout<<A[i]<<" ";
	return 0;
}