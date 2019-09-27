#include<bits/stdc++.h>
using namespace std;

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A

#define rep(i,n) for(ll i=0;i<(n);++i)
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
constexpr long long INF = (1LL<<60);
using ll = long long;
using vertex = struct vertex{ll to,cost;vertex(ll to,ll cost):to(to),cost(cost){}};
using weighted_adjlist = vector<vector<vertex>>;

auto Dijkstra(weighted_adjlist& adj,ll S){
  ll N=(ll)adj.size();
  vector<ll> dist(N,(1LL<<60));
  vector<ll> prev_v(N,-1LL);
  using pll = pair<ll,ll>;
  priority_queue<pll,vector<pll>,greater<>> que;
  dist[S]=0LL;
  que.emplace(dist[S],S);
  while(!que.empty()){
    ll cost,from;
    tie(cost,from) = que.top();
    que.pop();
    if(dist[from]<cost)continue;
    for(const auto& v:adj[from]){
      if( chmin(dist[v.to],dist[from]+v.cost) ){
        prev_v[v.to]=from;
        que.emplace(dist[v.to],v.to);
      }
    }
  }
  return dist;
  //return prev_v;
  //return make_pair(dist,prev_v);
}

void solve(){

  ll v,e,r;
  cin>>v>>e>>r;
  weighted_adjlist adj(v);
  rep(i,e){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].emplace_back(v,w);
  }
  auto dist = Dijkstra(adj,r);

  for(auto d:dist){
    if(d==INF)puts("INF");
    else cout<<d<<endl;
  }

}

main(){
  solve();
}