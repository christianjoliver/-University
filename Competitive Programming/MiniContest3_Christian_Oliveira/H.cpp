#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


ll max(ll a, ll b){
    return (a > b) ? a : b;
}


ll solve(ll m, vll pot, vll ef, ll n)
{
    ll dp[m + 1];
    memset(dp, 0, sizeof(dp));

    for (ll i = 1; i < n + 1; i++) {
        for (ll j = m; j >= 0; j--) {
            if (pot[i - 1] <= j)
                dp[j] = max(dp[j], dp[j - pot[i - 1]] + ef[i - 1]);
        }
    }
    return dp[m];
}


int main(){
    FASTIO;
    ll p;

    cin >> p;

    for(ll i = 0; i < p; i++){
        ll n, m, x, y;
        cin >> n >> m;
        vll ef, pot;
        for(ll j = 0; j < n; j++){
            cin >> x >> y;
            pot.PB(x);
            ef.PB(y);
        }
        cout << "Plataforma " << i+1 << ": " << solve(m, pot, ef, n) << "\n";
    }
    return 0;
}