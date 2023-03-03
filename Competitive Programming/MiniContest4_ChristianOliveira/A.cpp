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


void bellmanFord(vector<vector<ll>> graph, int V, int E){

    vll sDistance(V+1, INF);
    vi inQueue(V+1, 0);
    sDistance[1] = 0;
    queue<ll> Q;
    Q.push(1);
    inQueue[1] = 1;

    while(!Q.empty()){
        ll u = Q.front();
        Q.pop();
        inQueue[u] = 0;
        for(ll i = 0; i < graph[u].size(); i++){
            ll v = graph[u][i];
            if(sDistance[v] > sDistance[u] + 1){
                sDistance[v] = sDistance[u] + 1;

                if(!inQueue[v]){
                    Q.push(v);
                    inQueue[v] = 1;
                }
            }
        }
    }
    if(sDistance[V] == INF) cout << "IMPOSSIVEL\n";
    else cout << sDistance[V]+1 << "\n";
}

int main(){
    FASTIO;
    ll n, m, u, v;
    cin >> n >>  m;
    vector<vector<ll>> graph(n+1);

    for(ll i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].PB(v);
        graph[v].PB(u);
    }

    bellmanFord(graph, n, m);
    return 0;
}