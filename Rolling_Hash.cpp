#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)

class Rolling_Hash{
private:
  ll n;
  static constexpr ll base1=1007,base2=2009;
  static constexpr ll mod1=(1e9+7),mod2=(1e9+9);
  vector<ll> hash1,hash2,mpow1,mpow2;
public:
  Rolling_Hash(const string& s){
    n=s.size();
    hash1.resize(n+1,0);
    hash2.resize(n+1,0);
    mpow1.resize(n+1,1);
    mpow2.resize(n+1,1);
    for(ll i=0;i<n;++i){
      hash1[i+1] = (hash1[i]*base1+s[i])%mod1;
      hash2[i+1] = (hash2[i]*base2+s[i])%mod2;
      mpow1[i+1] = (mpow1[i]*base1)%mod1;
      mpow2[i+1] = (mpow2[i]*base2)%mod2;
    }
  }
  auto get(ll l,ll r){
    ll lefval = hash1[r]-hash1[l]*mpow1[r-l]%mod1;
    ll rigval = hash2[r]-hash2[l]*mpow2[r-l]%mod2;
    if(lefval<0)lefval+=mod1;
    if(rigval<0)rigval+=mod2;
    return make_pair(lefval,rigval);
  }
  auto get_LCP(ll a,ll b){
    ll len = min( n-a+1,n-b+1 );
    ll low=0,high=len;
    while( high-low>1 ){
      ll mid=(high+low)>>1;
      if(get(a,a+mid)!=get(b,b+mid))high=mid;
      else low=mid;
    }
    return low;
  }
};

void solve1(){
  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja
  string s,t;
  cin>>s>>t;
  ll n=s.size(),m=t.size();
  Rolling_Hash SR(s),TR(t);
  rep(i,n-m+1){
    if(SR.get(i,i+m)==TR.get(0,m)){
      cout<<i<<endl;
    }
  }
}
void solve2(){
  // https://atcoder.jp/contests/abc141/tasks/abc141_e
  ll n;
  string s;
  cin>>n>>s;
  Rolling_Hash rori(s);
  ll ans=0;
  for(ll i=0;i<n;++i){
    for(ll j=i+1;j<n;++j){
      ll lcp = rori.get_LCP(i,j);
      ans=max(ans,min(lcp,j-i));
    }
  }
  cout<<(ans)<<endl;
}

main(){
  //solve1();
  solve2();
}