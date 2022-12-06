#include<bits/stdc++.h>
using namespace std;
typedef long long ll;                 
typedef long double ld;
#define fi                  first
#define se                  second
#define pb                  push_back
// #define endl                "\n"
#define vl                  vector<ll>
#define pl                  pair<ll, ll>
#define vb                  vector<bool>
#define vvl                 vector<vector<ll>>
#define vpl                 vector<pair<ll,ll>>
#define I(x)                ll x; cin>>x;
#define IS(s)               string s; cin>>s;
#define A(x)                (x).begin(), (x).end()
#define rep(i, n)           for(ll i=0;i<n;i++)
#define V(x,n)              vl x(n); for(ll i=0;i<n;i++) cin>>x[i];

#ifndef ONLINE_JUDGE    
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x);  
#endif  
void _print(ll x){cerr<<x;}  
void _print(ld x){cerr<<x;}  
void _print(string x){cerr<<x;} 
void _print(char x){cerr<<x;} 
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define show(x) _prt(x);
template <class T> void _prt(vector<T> v) {for(T i: v) {cout<<i<<" ";} cout<<endl;}
template <class T> void _prt(vector<vector<T>> v) {for(auto i: v) {_prt(i);}}

const ll M = 1e9+7;     // 998244353
const ll INF = 1e18;
const ll N = 100005;
ll fact[N];
vb prime(N, true);  

void factorial(){fact[0] = 1;for(ll i=1;i<N;i++) fact[i]=(fact[i-1]*i)%M;}
ll power(ll b,ll e, ll m){b%=m;ll res=1; while(e>0){if(e%2){res=(res*b)%m;} b=(b*b)%m; e/=2;} return res;}
ll nCr(ll n,ll r){if(n<r) return 0; ll a=fact[n]; ll b=fact[n-r]*fact[r]; ll inv_b=power(b,M-2,M);return (a*inv_b)%M;}
ll nPr(ll n,ll r){if(n<r) return 0; ll a=fact[n]; ll b=fact[n-r]; ll inv_b=power(b,M-2,M); return (a*inv_b)% M;}
ll sum_all(vl v){ll ans=0; for(ll i=0; i<(ll)v.size(); i++){ans+=v[i];} return ans;}
/****************************************************************************************************************************/

 
void solve(){
    IS(s);
    map<char, ll> mp;
    for (ll i=0; i<s.length(); i++) {
        mp[s[i]] = i;
    }
    ll prev = 0;
    vl a, b;
    for (auto u: mp) {
        ll x = u.second;
        // cout << x << endl;
        if (x >= prev) {
            for (ll i=prev; i<=x; i++) {
                // cout << s[i] << endl;
                if (s[i] == s[x]) {
                    a.pb(s[i] - '0');
                } else {
                    
                    ll y = min(9, (s[i]-'0') + 1);
                    // cout << s[i] << " " << y << endl;
                    a.pb(y);
                }
            }
            prev = x+1;
        } 
    }
    sort(A(a));
    for (auto u: a) cout << u;
    // for (auto u: b) cout << u;
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cout << fixed << setprecision(3); 
    ll test = 1;
    cin >> test;
    while (test--){
        solve();
    }

    #ifndef ONLINE_JUDGE
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}