#include<bits/stdc++.h>
using namespace std;

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A

using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)
using edge = struct edge{ll from,to,cost;edge(ll from,ll to,ll cost):from(from),to(to),cost(cost){}};
using weighted_edge = vector<edge>;

class Union_Find {
private:
  ll n;
  vector<ll> parent;

public:
  Union_Find(ll v){
    n=v;
    parent.resize(n,-1);
  }

  ll root(ll v){
    if(parent[v]<0)return v;
    return parent[v]=root(parent[v]);
  }
  ll size(ll v){
    return -parent[root(v)];
  }
  bool connect(ll a,ll b){
    a=root(a);
    b=root(b);
    if(a==b)return false;
    if(size(a)<size(b)) swap(a,b);
    parent[a]+=parent[b];
    parent[b]=a;
    return true;
  }
  bool same(ll a,ll b){
    return root(a)==root(b);
  }

};

void solve(){

  ll v,e;
  cin>>v>>e;
  weighted_edge edges;
  rep(i,e){
    ll u,v,w;
    cin>>u>>v>>w;
    edges.emplace_back(u,v,w);
  }
  auto cmp = [](auto a,auto b){return a.cost<b.cost;};
  sort(edges.begin(),edges.end(),cmp);
  Union_Find uni(v);
  ll ans=0;
  for(const auto& e:edges){
    if( uni.same(e.from,e.to) )continue;
    uni.connect(e.from,e.to);
    ans+=e.cost;
  }
  cout<<(ans)<<endl;

}

main(){
  solve();
}