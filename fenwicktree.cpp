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

    class FenwickTree{
    public:
        vi fen;
        FenwickTree(int n){
            fen.resize(n+1,0); fen[0]=0;
        }
        void update(int i,int add){
            while(i<fen.size()){
                fen[i]+=add;
                i+=i & (-i);
            }
        }
        int sum(int i){
            int s=0;
            while(i>0)
            {
                s+=fen[i]; i=i-(i & (-i));
            }
            return s;
        }
        int rangesum(int l,int r){
            return sum(r)-sum(l);
        }
    };

void solve(){
    int n; cin>>n; int q; cin>>q; vi v(n+1); rep(i,1,n+1) cin>>v[i];
    FenwickTree ff(n+2);
    //rep(i,0,n) {ff.update(i+1,v[i]);}
      auto getsum=[](int x){
                string st=to_string(x); int ss=0;
                for(auto i:st) ss+=i-'0';
                    return ss;
            };
    rep(i,0,q){
        int type; cin>>type;
        if(type==1){
                int l,r; cin>>l>>r;
                ff.update(l,1); ff.update(r+1,-1);
        }
        else{
            int dd; cin>>dd;
            int x1=ff.rangesum(0,dd); debug(x1);
            int s=v[dd];
            while(x1--){
                s=getsum(s); if(s<10) break;
            }
            cout<<s<<endl;
          
        }
    }

}

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
    freopen("input2.txt", "w", stdout);

    freopen("input3.txt", "w", stderr);
#endif

   fast();
    int test=1;
   cin >> test;
    while (test--) solve();

    return 0;
}