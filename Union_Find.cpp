#include<bits/stdc++.h>
using namespace std;

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp

using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)

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
  ll n,q;
  cin>>n>>q;
  Union_Find uni(n);
  rep(i,q){
    ll c,x,y;
    cin>>c>>x>>y;
    if(c){
      auto tmp = uni.same(x,y);
      cout<<(tmp)<<endl;
    }
    else{
      uni.connect(x,y);
    }
  }
}

main(){
  solve();
}