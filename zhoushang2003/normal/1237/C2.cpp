#include<bits/stdc++.h>
using namespace std;
const int N=5e4+1;
struct S
{
	int x,y,z,i;
};
int n,q[N],t,Q[N],T;
S w[N];
bool C(S x,S y)
{
	if(x.x!=y.x)
		return x.x<y.x;
	if(x.y!=y.y)
		return x.y<y.y;
	return x.z<y.z;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i].x>>w[i].y>>w[i].z,w[i].i=i;
	sort(w+1,w+n+1,C);
	for(int i=1;i<=n;i++)
		if(i<n&&w[i].x==w[i+1].x&&w[i].y==w[i+1].y)
			cout<<w[i].i<<" "<<w[i+1].i<<'\n',i++;
		else
			q[++t]=i;
	for(int i=1;i<=t;i++)
		if(i<t&&w[q[i]].x==w[q[i+1]].x)
			cout<<w[q[i]].i<<" "<<w[q[i+1]].i<<'\n',i++;
		else
			Q[++T]=q[i];
	for(int i=1;i<=T;i+=2)
		cout<<w[Q[i]].i<<" "<<w[Q[i+1]].i<<'\n';
	return 0;
}