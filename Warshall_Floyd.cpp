#include<bits/stdc++.h>
using namespace std;

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C

using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)
constexpr long long INF = (1LL<<60);
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

auto Warshall_Floyd(vector<vector<ll>>& dist){
  ll v = dist.size();
  rep(i,v)dist[i][i]=0LL;
  rep(i,v)rep(j,v)rep(k,v){
    if(dist[j][i]==INF||dist[i][k]==INF)continue;
    chmin(dist[j][k],dist[j][i]+dist[i][k]);
  }
  bool negative_cycle=false;
  rep(i,v)rep(j,v)rep(k,v){
    if(dist[j][i]==INF||dist[i][k]==INF)continue;
    if( chmin(dist[j][k],dist[j][i]+dist[i][k]) ){
      negative_cycle=true;
    }
  }
  return negative_cycle;
}

void solve(){

  ll v,e;
  cin>>v>>e;

  vector<vector<ll>> dist (v,vector<ll>(v,INF));

  rep(i,e){
    ll u,v,w;
    cin>>u>>v>>w;
    chmin(dist[u][v],w);
  }

  bool negative_cycle=Warshall_Floyd(dist);

  if(negative_cycle)puts("NEGATIVE CYCLE");
  else{
    rep(i,v){
      rep(j,v){
        if(dist[i][j]==INF)cout<<"INF"<<(j+1==v?"\n":" ");
        else cout<<dist[i][j]<<(j+1==v?"\n":" ");
      }
    }
  }

}

main(){
  solve();
}