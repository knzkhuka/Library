#include<bits/stdc++.h>
using ll = long long;

template<class T>
class segtree {
private:
  ll n=1;
  T unit;
  std::vector<T> dat;
  std::function<T(T,T)> func;
public:
  segtree(){}
  segtree(std::vector<T>& a,T v,std::function<T(T,T)> f){
    build(a,v,f);
  }
  void build(std::vector<T>& a,T v,std::function<T(T,T)> f){
    ll sz=a.size();
    unit=v;
    func=f;
    while(n<sz)n<<=1LL;
    dat.resize(2*n-1,unit);
    for(int i=0;i<sz;++i)dat[i+n-1]=a[i];
    for(int i=n-2;i>=0;--i){
      dat[i]=func(dat[i*2+1],dat[i*2+2]);
    }
  }
  void update(ll idx,ll val){
    idx+=n-1;
    dat[idx]=val;
    while(idx){
      idx--;idx>>=1LL;
      dat[idx]=func(dat[idx*2+1],dat[idx*2+2]);
    }
  }
  T query(ll a,ll b,ll k=0,ll l=0,ll r=-1){
    if(r<0)r=n;
    if( b<=l || r<=a )return unit;
    if( a<=l && r<=b )return dat[k];
    else{
      auto left=query(a,b,2*k+1,l,(l+r)/2);
      auto right=query(a,b,2*k+2,(l+r)/2,r);
      return func(left,right);
    }
  }
};

// lowest common ancestor
class LCA{
private:
  using pll = std::pair<ll,ll>;
  ll n,root;
  std::vector<std::vector<ll>> adj;
  std::vector<ll> vs,depth,id;
  std::function<pll(pll,pll)> mindex = [](auto const& a,auto const& b){return min(a,b);};
  segtree<pll> RMQ;
public:
  LCA(){}
  LCA(std::vector<std::vector<ll>> const& a):adj(a),root(0){
    init();
  }
  LCA(std::vector<std::vector<ll>> const& a,ll r):adj(a),root(r){
    init();
  }
  void dfs(ll v,ll p,ll d,ll& k){
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(auto const& nv:adj[v]){
      if(nv!=p){
        dfs(nv,v,d+1,k);
        vs[k]=v;
        depth[k++]=d;
      }
    }
  }
  void init(){
    n=adj.size();
    vs.resize(2*n-1);
    depth.resize(2*n-1);
    id.resize(n);
    ll k=0;
    dfs(root,-1,0,k);
    constexpr ll INF = (1LL<<60);
    pll base(INF,INF);
    std::vector<std::pair<ll,ll>>dat(2*n-1);
    for(ll i=0;i<2*n-1;++i)dat[i]=std::make_pair(depth[i],i);
    RMQ.build(dat,base,mindex);
  }
  ll lca(ll u,ll v){
    auto t = RMQ.query(std::min(id[u],id[v]),std::max(id[u],id[v])+1LL);
    return vs[t.second];
  }
  ll operator[](ll i)const{
    return depth[id[i]];
  }
};

void solve1(){
  // https://atcoder.jp/contests/abc014/tasks/abc014_4
  ll n;
  std::cin>>n;
  std::vector<std::vector<ll>> adj(n);
  for(ll i=0;i<n-1;++i){
    ll x,y;
    std::cin>>x>>y;
    x--;y--;
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
  }
  LCA g(adj);
  ll q;
  std::cin>>q;
  std::vector<ll> a(q),b(q);
  for(ll i=0;i<q;++i){
    std::cin>>a[i]>>b[i];
    a[i]--;b[i]--;
  }
  for(ll i=0;i<q;++i){
    ll c=g.lca(a[i],b[i]);
    ll ans = g[a[i]]+g[b[i]]-g[c]*2+1;
    std::cout<<(ans)<<std::endl;
  }
}

main(){
  solve1();
}