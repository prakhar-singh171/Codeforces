#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define maxf(v) *max_element(v.begin(), v.end())
#define minf(v) *min_element(v.begin(), v.end())
#define revr(v) reverse(v.begin(), v.end())
#define inp(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &i : v) cout << i << " ";
#define tvs(v) for (auto &i : v)
#define rsort(v) sort(v.rbegin(), v.rend())
#define suv(s) set<int> s
#define mpg(s) map<int, int> s
#define pb push_back
#define pp pop_back
#define bb(v) v.back()
#define ss second
#define ff first
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rr return
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define summ(x) accumulate(all(x), 0LL)
#define prt(x) cout << x << endl
#define bk break
#define lb lower_bound
#define up upper_bound
#define lld long double
#define int long long
#define ull unsigned int
#define ll int
const int mod = 998244353;
const ll inf = LLONG_MAX;
const ll ninf = LLONG_MIN;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

namespace trees {
    class SGTree {
    public:
        int tt;
        vector<int> seg;
        SGTree(int n) {
            seg.resize(4 * n);
        }
        void build(int ind, int low, int high, set<int>& s) {
            if (low == high) {
                seg[ind] = (s.find(low) != s.end()) ? 1 : 0;
                return;
            }
            int mid = (low + high) / 2;
            build(2 * ind + 1, low, mid, s);
            build(2 * ind + 2, mid + 1, high, s);
            seg[ind] = max(seg[2 * ind + 1],seg[2 * ind + 2]);
        }
        void update(int ind, int updind, int val, int left, int right) {
            if (left == right) {
                if (left == updind) seg[ind] = val;
                return;
            }
            if(l>right || h<low) return;
            int mid = (left + right) / 2;
            if (updind <= mid) update(2 * ind + 1, updind, val, left, mid);
            else update(2 * ind + 2, updind, val, mid + 1, right);
            seg[ind] = max(seg[2 * ind + 1],seg[2 * ind + 2]);
        }
        void query(int ind, int low, int high, int l, int r, int k) {
            if (low == high) {
                tt = low;
                return;
            }
            int mid = (low + high) / 2;
            int left_count = seg[2 * ind + 1];
            if (k <= left_count) query(2 * ind + 1, low, mid, l, mid, k);
            else query(2 * ind + 2, mid + 1, high, mid + 1, r, k - left_count);
        }
    };
}

using namespace trees;
const int nn=2000005
void solve() {
  int n; cin>>n; vi v(n); inp(v);
  vi L(2000005);
  L[v[0]+1]=nn; set<int> s; s.insert(v[0])+1;
  rep(i,1,n){
    int x=v[i]+1;
    auto it=s.lower_bound(x);



  }

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input3.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    fast();
    int test = 1;
    // cin >> test;
    while (test--) solve();

    return 0;
}
