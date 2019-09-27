#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)

class SegmentTree {
private:
  ll n=1,unit;
  vector<ll> dat;
  function<ll(ll,ll)> func;
public:
  SegmentTree(vector<ll>& a,ll v,function<ll(ll,ll)> f){
    build(a,v,f);
  }
  void build(vector<ll>& a,ll v,function<ll(ll,ll)> f){
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
  void add(ll idx,ll val){
    idx+=n-1;
    dat[idx]+=val;
    while(idx){
      idx--;idx>>=1LL;
      dat[idx]=func(dat[idx*2+1],dat[idx*2+2]);
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
  auto query(ll a,ll b,ll k=0,ll l=0,ll r=-1){
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

void solve_RMQ(){
  int n,q;
  cin>>n>>q;
  ll base = (1LL<<31)-1;
  vector<ll> a(n,base);
  auto f = [](auto a,auto b){return min(a,b);};
  SegmentTree rmq(a,base,f);
  rep(i,q){
    ll c,x,y;
    cin>>c>>x>>y;
    if(c){
      auto tmp = rmq.query(x,y+1);
      cout<<(tmp)<<endl;
    }
    else{
      rmq.update(x,y);
    }
  }
}
void solve_RSQ(){
  ll n,q;
  cin>>n>>q;
  ll base=0;
  auto f = [](auto a,auto b){return a+b;};
  vector<ll> a(n);
  SegmentTree rsq(a,base,f);
  rep(i,q){
    ll c,x,y;
    cin>>c>>x>>y;
    if(c){
      x--;y--;
      auto tmp=rsq.query(x,y+1);
      cout<<(tmp)<<endl;
    }
    else{
      x--;
      rsq.add(x,y);
    }
  }
}

main(){
  // solve_RMQ();
  // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  // solve_RSQ();
  // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
}