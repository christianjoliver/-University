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

vll fat {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880,
               3628800, 39916800, 479001600, 6227020800, 87178291200,
                1307674368000, 20922789888000, 355687428096000,
                6402373705728000, 121645100408832000, 2432902008176640000};

vll result;

int solve(ll n){
    ll i;
    auto x = lower_bound(fat.begin(), fat.end(), n);
    if(*x != n) x--;
    ll cont = 0;
    if(n == 1){
        result.PB(1);
        return 1;
    }
    for(i = x - fat.begin(); i > -1; i--, x--){
        if((*x + cont) <= n){
            cont += *x;
            result.PB(i);
        }
    }
    if(cont != n) return 0;
    return 1;
}

int main() {
	FASTIO;
	ll T, i, j, n;
	cin >> T;
	for(i = 0; i < T; i++){
	    cin >> n;
        if(solve(n)){
            cout << "Teste " << (i+1) << ": ";
            sort(all(result));
            ll tam = result.size();
            for(j = 0; j < tam; j++){
                if(j!=result.size()-1)
                    cout << result[j] << "!+";
                else
                    cout << result[j] << "!";
            }
        }
        else cout << "Teste " << (i+1) << ": impossivel";
        result.clear();
        cout << "\n";
	}
	return 0;
}