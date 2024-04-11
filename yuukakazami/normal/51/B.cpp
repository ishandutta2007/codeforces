#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <numeric>
#include <cstdio>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define FOREACH(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define FOR(i,a,b) for(int i=a;i<b;i++)//for i in [a,b)
#define MP make_pair
using namespace std;
typedef long long int64;
typedef pair<int,int> ipair;
typedef vector<int> vi;

string S,s;
int at=0;
bool check(string s)
{
    return S.substr(at,s.size())==s;
}
void eat(string s)
{
    at+=s.size();
}
int parseTable();
int parseRow();
int parseCell();

multiset<int> ansSet;

int parseTable()
{
    eat("<table>");
    int total=0;
    while(check("<tr>"))
        total+=parseRow();
    eat("</table>");
    ansSet.insert(total);
    return total;
}

int parseRow()
{
    eat("<tr>");
    int total=0;
    while(check("<td>"))
        total+=parseCell();
    eat("</tr>");
    return total;
}

int parseCell()
{
    eat("<td>");
    while(check("<table>"))
        parseTable();
    eat("</td>");
    return 1;
}
int main()
{
    //freopen("in","r",stdin);
    while(cin>>s)S+=s;
    S+="$$$$$$$$$";
    parseTable();
    FOREACH(it,ansSet)
        cout<<*it<<" ";
    cout<<endl;
}