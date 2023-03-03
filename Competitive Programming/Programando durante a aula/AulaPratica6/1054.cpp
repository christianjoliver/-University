#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<string,ll> pll;
typedef vector<pair<ll, char>> vplc;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
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




int buscaSalto(vplc vp, ll qnt, ll D){

    ll maior = 0;
    ll dist = 0;
    for(ll i = 1; i < qnt; i++){
        if(vp[i].second == 'S'){
            if(vp[i+1].first - dist > maior) maior = vp[i+1].fist - dist;
            dist = vp[i].first;
        }
        else{
            dist =
        }
    }
}


int main() {
	FASTIO;
    ll T, N, D, C;
    char tam, s;

    cin >> T;

    for(ll i = 0; i < T; i++){
        vplc vp;
        cin >> N >> D;
        vp.push_back(0, 'B');
        for(ll j = 0; j < N; j++){
            cin >> tam >> s;
            cin >> C;
            auto a = make_pair(C, tam);
            vp.push_back(a);
        }

        for(auto l: vp){ cout << l.second << " " << l.first << "\n"; }
    }
	return 0;
}