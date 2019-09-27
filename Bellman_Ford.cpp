#include<bits/stdc++.h>
using namespace std;

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B

using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)
constexpr long long INF = (1LL<<60);
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
using edge = struct edge{ll from,to,cost;edge(ll from,ll to,ll cost):from(from),to(to),cost(cost){}};
using weighted_edge = vector<edge>;

auto Bellman_Ford(weighted_edge& edges,ll n,ll s,ll k=1){
  vector<ll> dist(n,INF);
  dist[s]=0LL;
  rep(i,n*k){
    for(const auto& e:edges){
      if(dist[e.from]==INF)continue;
      chmin(dist[e.to],dist[e.from]+e.cost);
    }
  }
  bool negative_cycle=false;
  rep(i,n*k){
    for(const auto& e:edges){
      if(dist[e.from]==INF)continue;
      if( chmin(dist[e.to],dist[e.from]+e.cost) ){
        negative_cycle=true;
      }
    }
  }
  return make_pair(dist,negative_cycle);
}

void solve(){

  ll v,e,r;
  cin>>v>>e>>r;
  weighted_edge edges;
  rep(i,e){
    ll u,v,w;
    cin>>u>>v>>w;
    edges.emplace_back(u,v,w);
  }
  bool negative_cycle;
  vector<ll> dist;
  tie(dist,negative_cycle) = Bellman_Ford(edges,v,r,2);

  if(negative_cycle)puts("NEGATIVE CYCLE");
  else{
    for(auto d:dist){
      if(d==INF)puts("INF");
      else cout<<d<<endl;
    }
  }

}

main(){
  solve();
}