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





void ganho(vector<ll>pos, vector<ll>lucro, ll N, ll K){
    vector<ll>temp(N+1);
    ll j;
    temp[0] = 0;
    for(ll m = 1; m <= N; m++){

        ll j = lower_bound(pos.begin(), pos.end(), pos[m]-K) - pos.begin();

        if(j >= 1 && pos[j]+K > pos[m]) { j--; }

        if(temp[m-1] > (temp[j] + lucro[m])) { temp[m] = temp[m-1]; }
        else { temp[m] = temp[j] + lucro[m]; }
    }
    cout << temp[N] << "\n";
}


int main() {
	FASTIO;
	ll ct, N, K;

	cin >> ct;

	for(ll i = 0; i < ct; i++){
	    cin >> N >> K;

    	vector<ll>pos(N+1);
	    vector<ll>lucro(N+1);
	    for(ll j = 1; j <= N; j++){ cin >> pos[j]; }
	    for(ll j = 1; j <= N; j++){ cin >> lucro[j]; }

	    ganho(pos, lucro, N, K);
	}


	return 0;
}