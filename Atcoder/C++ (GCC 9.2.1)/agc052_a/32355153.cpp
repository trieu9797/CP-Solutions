/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

/*
Day start : 09/06/2022
To - day  : 10/06/2022
Counting : 0004
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 998244353;
void add(int &a, int b, int mod = MOD){ a += b; while (a < 0) a += mod; while (a >= mod) a -= mod; }
int sum(int a, int b, int mod = MOD){ return add(a, b, mod), a; }
void mul(int &a, int b, int mod = MOD){ a = (a * 1LL * b) % mod; }
int prod(int a, int b, int mod = MOD){ return mul(a, b, mod), a; }
int bpow(int a, int b, int mod = MOD){ int ans = 1; while (b){ if (b & 1){ mul(ans, a, mod); } mul(a, a, mod); b >>= 1; } return ans; }
int Inv(int a, int mod = MOD){ return bpow(a, mod - 2, mod); }
int Div(int a, int b, int mod = MOD) { return prod(a, Inv(b, mod), mod); }

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
//const int B = sqrt(N) + 5;

void solve()
{
	int n; cin >> n;
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	for(int i = 1; i <= n; ++i) cout << 0;
    for(int i = 1; i <= n; ++i) cout << 1;
    cout << 0 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}