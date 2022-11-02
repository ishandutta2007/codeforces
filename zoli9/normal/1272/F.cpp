#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int n1, n2;
string s1, s2;
int dp[209][209][209];
int lepes[209][209][209];
int infi=1e9;
int f(int df, int x, int y)
{
    if(df>200) return infi;
    if(lepes[df][x][y]>0) return dp[df][x][y];
    if(x==n1 && y==n2)
    {
        lepes[df][x][y]=2;
        return dp[df][x][y]=df;
    }
    int xp=x;
    if(x<n1 && s1[x]=='(') xp++;
    int yp=y;
    if(y<n2 && s2[y]=='(') yp++;
    int f1=f(df+1, xp, yp);
    xp=x;
    if(x<n1 && s1[x]==')') xp++;
    yp=y;
    if(y<n2 && s2[y]==')') yp++;
    int f2=infi;
    if(df>0) f2=f(df-1, xp, yp);
    if(f1<f2) lepes[df][x][y]=1;
    else lepes[df][x][y]=2;
    dp[df][x][y]=min(f1, f2)+1;
    return dp[df][x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>s2;
    n1=s1.size();
    n2=s2.size();
    int ans=f(0, 0, 0);
    int i1=0;
    int i2=0;
    int di=0;
    while(i1<n1 || i2<n2 || di>0)
    {
        if(i1==n1 && i2==n2)
        {
            cout<<")";
            di--;
            continue;
        }
        f(di, i1, i2);
        if(lepes[di][i1][i2]==1)
        {
            cout<<"(";
            di++;
            if(i1<n1 && s1[i1]=='(') i1++;
            if(i2<n2 && s2[i2]=='(') i2++;
        }
        else
        {
            cout<<")";
            di--;
            if(i1<n1 && s1[i1]==')') i1++;
            if(i2<n2 && s2[i2]==')') i2++;
        }
    }
    cout<<endl;
    return 0;
}