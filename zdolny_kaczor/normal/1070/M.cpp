#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define dor >debug & operator<< (
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug &>::type operator<< (c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c * x) -> decltype(cerr << *x, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << endl;}
eni(==) ris << range(begin(i), end(i));}
eni(!=) cerr << i; ris;}
sim dor rge<c> x) {
	cerr << "[";
	for (c it = x.b; it != x.e; ++it)
		*this << ", " + 2 * (x.b == it) << *it;
	ris << "]";
}
sim, class b dor pair <c,b> x) {ris << "(" << x.first << ", " << x.second << ")";}
#else
sim dor const c&) {ris;}
#endif
};
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) << ": " << a[i] << "] " 
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] " 
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
const int nax=10*1007;
using bn=bitset<nax>;

int n, m;
int k;
int tab[nax];
pii pun[nax];

pii operator - (pii a, pii b)
{
	return {a.first-b.first, a.second-b.second};
}

int ilowek(pii s, pii a, pii b)
{
	a=a-s;
	b=b-s;
	return a.first*b.second-a.second*b.first;
}

void wypisz(int a, int b)
{
	if (a>n)
		swap(a, b);
	printf("%d %d\n", b-n, a);
}

pii wsp[nax];

bool mniej(pii a, pii b)
{
	return ilowek({0, 0}, wsp[a.first], wsp[b.first])>0;
}

//~ bool popun(int a, int b)
//~ {
	//~ return pun[a]<pun[b];
//~ }

int znak(int v)
{
	if (!v)
		return 0;
	return v/abs(v);
}

int typ(int v)
{
	return (v<=n);
}

void rek(vi wek)
{
	random_shuffle(wek.begin(), wek.end());
	debug << imie(wek);
	assert(!wek.empty());
	if ((int)wek.size()==1)
	{
		assert(!tab[wek[0]]);
		return;
	}
	if ((int)wek.size()==2)
	{
		assert(tab[wek[0]]+tab[wek[1]]==1);
		wypisz(wek[0], wek[1]);
		return;
	}
	//~ sort(wek.begin(), wek.end(), popun);
	for (int &i : wek)
	{
		if (!tab[i])
		{
			swap(wek[0], i);
			break;
		}
	}
	vi dol, gor;
	int cen=wek[0];
	for (int i=1; i<(int)wek.size(); i++)
	{
		if (pun[wek[i]]<pun[cen])
			dol.push_back(wek[i]);
		else
			gor.push_back(wek[i]);
	}
	for (int i : gor)
		wsp[i]=pun[i]-pun[cen];
	for (int i : dol)
		wsp[i]=pun[cen]-pun[i];
	vector <pii> dos;
	for (int i : gor)
		dos.push_back({i, 1});
	for (int i : dol)
		dos.push_back({i, 0});
	sort(dos.begin(), dos.end(), mniej);
	int bil=0;
	for (int i : gor)
		bil+=tab[i]-1;
	if (!bil && (!gor.empty() && !dol.empty()))
	{
		gor.push_back(cen);
		dol.push_back(cen);
		debug << "dziele " << gor << " " << dol;
		rek(gor);
		rek(dol);
		return;
	}
	debug << imie(dos);
	int poz=-1;
	int nag=gor.size();
	int nad=dol.size();
	for (pii i : dos)
	{
		poz++;
		if (i.second)//gora
		{
			bil-=tab[i.first]-1;
			nag--;
			nad++;
		}
		else//dol
		{
			bil+=tab[i.first]-1;
			nad--;
			nag++;
		}
		if (!nad || !nag)
			continue;
		if (!bil)
		{
			vi raz{cen}, dwa{cen};
			for (int j=0; j<(int)dos.size(); j++)
			{
				if ((j<=poz)==dos[j].second)
					raz.push_back(dos[j].first);
				else
					dwa.push_back(dos[j].first);
			}
			debug << "dziele2 " << raz << " " << dwa;
			rek(raz);
			rek(dwa);
			return;
		}
	}
	//~ rek(wek);
	//~ return;
	bil=0;
	for (int i : gor)
		bil+=tab[i]-1;
	poz=-1;
	nag=gor.size();
	nad=dol.size();
	queue <int> g, d;
	for (pii i : dos)
	{
		if (i.second)
			g.push(i.first);
		else
			d.push(i.first);
	}
	for (pii i : dos)
	{
		poz++;
		int pam=bil;
		if (i.second)//gora
		{
			bil-=tab[i.first]-1;
			nag--;
			nad++;
			d.push(i.first);
			g.pop();
		}
		else//dol
		{
			bil+=tab[i.first]-1;
			nad--;
			nag++;
			g.push(i.first);
			d.pop();
		}
		if (!nad || !nag)
			continue;
		if (pam<0 && bil>0)
		{
			//~ cerr << "mam " << endl;
			vi raz, dwa;
			while(!g.empty())
			{
				raz.push_back(g.front());
				g.pop();
			}
			while(!d.empty())
			{
				dwa.push_back(d.front());
				d.pop();
			}
			int on=raz.back();
			raz.pop_back();
			debug << imie(on);
			wypisz(cen, on);
			tab[on]--;
			int stara=tab[on];
			raz.push_back(on);
			dwa.push_back(on);
			tab[on]=-pam;
			rek(raz);
			tab[on]=stara+pam;
			rek(dwa);
			return;
		}
		if (pam>0 && bil<0)
		{
			//~ cerr << "mam2 " << endl;
			vi raz, dwa;
			while(!g.empty())
			{
				raz.push_back(g.front());
				g.pop();
			}
			while(!d.empty())
			{
				dwa.push_back(d.front());
				d.pop();
			}
			int on=dwa.back();
			dwa.pop_back();
			debug << imie(on);
			wypisz(cen, on);
			tab[on]--;
			int stara=tab[on];
			raz.push_back(on);
			dwa.push_back(on);
			tab[on]=-bil;
			rek(raz);
			tab[on]=stara+bil;
			rek(dwa);
			return;
		}
	}
	for (int i : gor)
		wsp[i]=pun[i]-pun[cen];
	for (int i : dol)
		wsp[i]=pun[i]-pun[cen];
	sort(dos.begin(), dos.end(), mniej);
	if (typ(dos.back().first)==typ(cen))
		reverse(dos.begin(), dos.end());
	assert(typ(dos.back().first)!=typ(cen));
	int x=dos.back().first;
	dos.pop_back();
	vi daj;
	debug << imie(dos);
	for (pii i : dos)
		daj.push_back(i.first);
	wypisz(cen, x);
	tab[x]--;
	if (tab[x]==0)
		daj.push_back(cen);
	else
		daj.push_back(x);
	rek(daj);
	return;
	
	assert(0);
}

void test()
{
	printf("YES\n");
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		tab[i]=0;
	for (int i=1; i<=m; i++)
		scanf("%d", &tab[n+i]);
	k=n+m;
	for (int i=1; i<=k; i++)
		scanf("%d%d", &pun[i].first, &pun[i].second);
	vi start(k);
	for (int i=0; i<k; i++)
		start[i]=i+1;
	rek(start);
	//~ debug;
	//~ debug;
	//~ debug;
}

int main(int argc, char *argv[])
{
	srand(time(0));
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}