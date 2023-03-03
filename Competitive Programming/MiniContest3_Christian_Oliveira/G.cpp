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

bool flag = false;

void solve(ll t, ll m, ll s, ll var, vll moedas){

    if(var == 0 && s != t) s = 0;

    if(s > t) return;

    if(s == t){
        flag = true;
        return;
    }

    for(ll i = m-1; i >= 0; i--){
        if((s + moedas[i]) <= t && i != var){
            s += moedas[i];
            solve(t, m-1, s, i, moedas);
        }
    }
}

int main() {
	FASTIO;
	ll t, m, x;
    vll moedas;

    cin >> t >> m;
	for(ll i = 0; i < m; i++){
	    cin >> x;
	    moedas.PB(x);
	}

    solve(t, m, 0, -1, moedas);

	if(flag) cout << "S\n";
	else cout << "N\n";

	return 0;
}