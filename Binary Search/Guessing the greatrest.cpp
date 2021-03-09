#include<bits/stdc++.h>
using namespace std;

#define forever         while(true)
#define int 			long long
#define rep(i, s, n)    for(int i=s;i<n;i++)
#define fo(i, n)        rep(i, 0, n)
#define tr(c, it)       for(auto it : c)
#define all(c)          (c).begin(), (c).end()
#define sz(x)           (int)(x.size())
#define ff              first
#define ss              second
#define pb              push_back
#define ppb             pop_back
#define pf              push_front
#define ppf             pop_front
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define st  			set<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define w(x)            int x; cin>>x; while(x--)

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;


map<pii, int> qans;

int query(int l, int r) {
	if (qans.count({l, r})) {
		return qans[ {l, r}];
	}
	if (l == r) {
		return -1;
	}
	cout << "? " << l << " " << r << endl;
	int ans;
	cin >> ans;
	return qans[ {l, r}] = ans;
}
void answer(int x) {
	cout << "! " << x << endl;
	exit(0);
}

void solve() {
	int n;
	cin >> n;

	int smx = query(1, n);
	int ans;
	if (smx == query(1, smx)) {
		// [1 to smx]
		int L = 1, U = smx;
		while (L <= U) {
			int m = (L + U) / 2;
			if (query(m, smx) == smx) {
				ans = m;
				L = m + 1;
			}
			else {
				U = m - 1;
			}
		}
	}
	else {
		// [smx to r]
		int L = smx, U = n;
		while (L <= U) {
			int m = (L + U) / 2;
			if (query(smx, m) == smx) {
				ans = m;
				U = m - 1;
			}
			else {
				L = m + 1;
			}
		}
	}
	answer(ans);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef SIEVE
	sieve();
#endif
#ifdef NCR
	init();
#endif
	solve();
	return 0;
}
 
