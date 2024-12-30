

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
 
 namespace Disjoint{
    class DisjointSet {
    public:
    vector<int> rank, parent, size; 

    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node]=findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
}
 using namespace Disjoint;
 void solve(){
    int n; cin>>n; string st; cin>>st;
    DisjointSet v(30); vi tt(30,1);
    map<char,char> mp; string res="";
    rep(i,0,n){
        if(v.parent[st[i]-'a']!=(st[i]-'a')){
            res.pb(v.parent[st[i]-'a']+'a'); continue;
        }
        int tt1=0; 
        for(char ch='a';ch<='z';ch++){
            if(ch==st[i]) continue;
             //   if(i==25) {debug(v.findUPar(25));}
            if(tt[ch-'a']==1 && v.findUPar(ch-'a')!=v.findUPar(st[i]-'a')){
                v.parent[st[i]-'a']=ch-'a'; tt[ch-'a']++;
                //mp[st[i]]=ch; tt1++;
                tt1++;
                res=res+ch; break;
            }

        }
        if(i==25) cerr<<tt[0]<<endl;
         if(tt1==0) 
          {rep(i,0,26) 
      {if(tt[i]==1)
      {
        res.pb('a'+i); break;
    }
}
}

    }
   
     
        cout<<res<<endl;

 }

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input5.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    freopen("Error.txt", "w", stderr);
#endif

    fast();
    int test=1;
    cin >> test;
    while (test--) solve();

    return 0;
}


