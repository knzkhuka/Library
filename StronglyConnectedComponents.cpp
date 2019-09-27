#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp

class StronglyConnectedComponents {
private:
  ll n;
  vector<vector<ll>> dag,rdag,st;
  vector<ll> comp,order;
  vector<bool> used;
public:
  StronglyConnectedComponents(const vector<vector<ll>>& adj){
    n = adj.size();
    comp.resize(n);
    used.resize(n);
    dag.resize(n);
    rdag.resize(n);
    for(ll i=0;i<n;++i){
      for(const auto& x:adj[i]){
        dag[i].emplace_back(x);
        rdag[x].emplace_back(i);
      }
    }
  }

  inline auto operator[](ll idx)const{
    return comp[idx];
  }
  void dfs(ll now_v){
    if(used[now_v])return;
    used[now_v]=true;
    for(const auto& next_v:dag[now_v]) dfs(next_v);
    order.push_back(now_v);
  }
  auto rdfs(ll now_v,ll num){
    if(comp[now_v])return false;
    comp[now_v]=num;
    for(const auto& next_v:rdag[now_v]) rdfs(next_v,num);
    return true;
  }
  auto build(){
    for(ll i=0;i<n;++i) dfs(i);
    reverse(order.begin(),order.end());
    ll num=1;
    for(const auto& v:order) num+=rdfs(v,num);
    st.resize(num);
    for(ll i=0;i<n;++i){
      st[comp[i]].emplace_back(i);
    }
    return st;
  }
  void dump(){
    rep(i,n)cout<<i<<" ";cout<<endl;
    rep(i,n)cout<<comp[i]<<" ";cout<<endl;
  }
};

main(){

  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> adj(n);
  rep(i,m){
    ll s,t;
    cin>>s>>t;
    adj[s].emplace_back(t);
  }

  StronglyConnectedComponents scc(adj);
  scc.build();

  ll q;
  cin>>q;
  rep(i,q){
    ll u,v;
    cin>>u>>v;
    if(scc[u]==scc[v])puts("1");
    else puts("0");
  }


}