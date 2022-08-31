/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

/*Pragma*/
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Os")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

/*Normal define*/
#define int long long
#define ll long long
//#define endl '\n'
#define gcd __gcd
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>
//#define p prev
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define count1 __builtin_popcountll

/*For define*/
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define foR(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define forN(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define foRN(i,a,b,c) for(ll i=a;i>=b;i-=c)
#define fora(i, a) for (auto i : a)

/*push-pop-pair define*/
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define x first
#define y second

/*Print define*/
#define write(a, l, r) for (ll ik = l; ik <= r; ik++) cout << a[ik] << ' '; cout << endl
#define writeln(a, l, r) for (ll ik = l; ik <= r; ik++) cout << a[ik] << endl

/*Type-def*/
typedef unsigned long long  ull;
typedef vector<ll>      vi;
typedef pair<ll, ll>        ii;
typedef long double         ld;

/* Calculation with MODULO*/

const int MOD = 1e9 + 7;

ll dec(ll x, ll y, int mod = MOD) {return (x-y+mod)%mod;}
ll add(ll x, ll y, int mod = MOD) {return (x + y) % mod;}
ll mul(ll x, ll y, int mod = MOD) {return ((x%mod) * (y%mod)) % mod;}
ll bpow(ll x, ll y, int mod = MOD) {ll res = 1; while (y) {if (y & 1) res = mul(res, x, mod); x = mul(x, x, mod); y >>= 1;} return res;}
ll ModInverse(ll x, int mod = MOD) {return bpow(x, mod - 2, mod);}
ll Div(ll x, ll y, int mod = MOD) {return mul(x, ModInverse(y, mod), mod);}
bool GetBit(int val, int num) {return ((val>>num) & 1);}

/*Some simple checking and calculation function*/
string yn(bool k){if (k) return "Yes"; else return "No";}
__int128 binpower(__int128 base, __int128 e, __int128 mod) {__int128 result = 1;base %= mod;while (e){if (e & 1)result = (__int128)result * base % mod;base = (__int128)base * base % mod;e >>= 1;    }return result;}
bool check_composite(__int128 n, __int128 a, __int128 d, int s) {__int128 x = binpower(a, d, n); if (x == 1 or x == n - 1)return false;for (int r = 1; r < s; r++) {x = (__int128)x * x % n;if (x == n - 1)return false;}return true;};
bool checkprime(__int128 n) {if (n < 2)return false;int r = 0;__int128 d = n - 1;while ((d & 1) == 0) {d >>= 1;r++;}for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {if (n == a)return true;if (check_composite(n, a, d, r))return false;}return true;}
bool checksqr(ll k){return (trunc(sqrt(k))*trunc(sqrt(k))==k);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
//ll sum(ll n) {return n*(n+1)/2;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const int B = sqrt(1e9 + 7) + 100;

int a[N], b[N];
multiset <int> s;
vector <ii> e;
vector <int> v;
map <int, vector<int>> lst;
map <int, bool> f;

void dfs(int u){
    f[u] = true;
    fora(i, lst[u]){
        if (f[i]) continue;
        dfs(i);
    }
}

map <int, int> cnt;

void solve(){
    int k, n, xorsum = 0;
    cin >> n;
    For(i,1,n) cin >> a[i], a[0] ^= a[i], cnt[a[i]]++;
    cnt[a[0]]++;
    For(i,1,n) cin >> b[i], b[0] ^= b[i], cnt[b[i]]--;
    cnt[b[0]]--;
    fora(i, cnt){
        if (i.y != 0) {cout << -1; return;}
    }
    int cnt = -1;
    For(i,1,n){
        if (a[i] != b[i]){
            cnt++;
            lst[a[i]].pb(b[i]);
            lst[b[i]].pb(a[i]);
            v.pb(a[i]); v.pb(b[i]);
        }
    } v.pb(a[0]); v.pb(b[0]);
    fora(i, v){
        if (!f[i]) cnt++, dfs(i);
    }
    cout << cnt;
}

signed main(){
    FastIO
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}
/*
//Delete define endl when interactive prolem

INPUT :
4 10
0 1 6 5 
1 1 3 4
2 2 2 1
3 4 4
2 1 2 4
2 2 4 1
2 1 4 7
2 2 4 2
3 1 4
1 1 2 1
2 3 3 4

OUTPUT :
5
7

If it WA, check :
- Special case (Usually, n=1)
- WRONG FORMAT OUTPUT
- Check reading
- Change (ll) to (ull)
- lleger Overflow (The number that bigger than 2^63-1)
*/