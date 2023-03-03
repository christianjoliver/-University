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

int n, m;
vector<int> v;
vector<vector<int>> graph;

int solve(int a, int b){

    for(ll i : graph[a]){
        if(i != b){

            if(v[i]) return 1;
            v[i] = a;
            if(solve(i, a)) return 0;

        }
    }
    return 0;
}


int main() {
    FASTIO;
    int s = 0, a, b;

    cin >> n >> m;

    v.resize(n+1, 0);
    graph.resize(n+1);
    for(ll i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].PB(b);
        graph[b].PB(a);
    }

    for(ll i = 1 ; i <= n; i++){
        if(!v[i]){
            v[i] = i;
            if(solve(i, 0)){ s = 1 ; break; }
        }
    }

    if(s) cout << "CANDIDATO!" << "\n";
    else cout << "IMPOSSIVEL!" << "\n";

    return 0;
}