#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
string s;
int qu;
int n;
int A[5000009];
int B[5000009];
int C[5000009];
void init(int cs, int k, int v)
{
    if(k==v)
    {
        A[cs]=0;
        B[cs]=0;
        C[cs]=0;
        if(s[k]=='(') B[cs]++;
        if(s[k]==')') C[cs]++;
        return;
    }
    init(2*cs, k, (k+v)/2);
    init(2*cs+1, (k+v)/2+1, v);
    int t=min(B[2*cs], C[2*cs+1]);
    A[cs]=A[2*cs]+A[2*cs+1]+t;
    B[cs]=B[2*cs]+B[2*cs+1]-t;
    C[cs]=C[2*cs]+C[2*cs+1]-t;
    return;
}
pair<int, pair<int, int> > kerdez(int cs, int k, int v, int x, int y)
{
    if(y<k || v<x) return {0, {0, 0}};
    if(x<=k && v<=y)
    {
        return {A[cs], {B[cs], C[cs]}};
    }
    pair<int, pair<int, int> > h1=kerdez(2*cs, k, (k+v)/2, x, y);
    pair<int, pair<int, int> > h2=kerdez(2*cs+1, (k+v)/2+1, v, x, y);
    int newt=min(h1.S.F, h2.S.S);
    int newa=h1.F+h2.F+newt;
    int newb=h1.S.F+h2.S.F-newt;
    int newc=h1.S.S+h2.S.S-newt;
    return {newa, {newb, newc}};
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    n=s.size();
    init(1, 0, n-1);
    cin>>qu;
    for(int u=1; u<=qu; u++)
    {
        int eleje, vege;
        cin>>eleje>>vege;
        cout<<2*kerdez(1, 0, n-1, eleje-1, vege-1).F<<endl;
    }
    return 0;
}