/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    if (s[0] != s.back()){
        cout << 1;
        return;
    } else {
        for(int i = 1; i < n - 1; ++i){
            if (s[0] != s[i] && s[0] != s[i + 1]){
                cout << 2;
                return;
            }
        }
    }
    cout << -1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);

    int t = 1; // cin >> t;
    while (t--)
    {
        solve();
    }
}