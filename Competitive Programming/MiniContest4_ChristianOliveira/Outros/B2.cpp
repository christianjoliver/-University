#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
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

ll ct;
ll alc;
vll Alc;

void auxCount(vvi graph, ll v){

    alc += 1;
    Alc[v] += alc;

    for(auto u : graph[v])
        if(Alc[u] == 0) auxCount(graph, u);
}

void countComponents(ll V, vvi graph){
    ct = 0;
    alc = 0;
    Alc.resize(V+1, 0);

    auxCount(graph, 1);

    ct++;
    for(ll i = 2; i <= V; i++){
        if(Alc[i] == 0){
            auxCount(graph, i);
            ct++;
        }
    }
    cout << ct-1 << "\n";
}

int main(){
    FASTIO;
    ll n, m, a, b;
    cin >> n >> m;

    vvi graph(n+1, vi(0, 0));

    for(ll i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].PB(b);
        graph[b].PB(a);
    }

    countComponents(n, graph);

    return 0;
}