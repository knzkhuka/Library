#include<bits/stdc++.h>

// https://ei1333.github.io/luzhiled/snippets/math/mod-int.html
// http://noshi91.hatenablog.com/entry/2019/03/31/174006

template<long long MOD>
struct mod_int{
  using ll = long long;
  ll val;
  constexpr mod_int():val(0){}
  constexpr mod_int(ll x)noexcept:val(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD){}
  constexpr ll value()const noexcept{return val;}
  constexpr mod_int operator+(mod_int const& rhs){
    return mod_int(*this)+=rhs;
  }
  constexpr mod_int operator-(mod_int const& rhs){
    return mod_int(*this)-=rhs;
  }
  constexpr mod_int operator*(mod_int const& rhs){
    return mod_int(*this)*=rhs;
  }
  constexpr mod_int operator/(mod_int const& rhs){
    return mod_int(*this)/=rhs;
  }
  constexpr mod_int &operator+=(mod_int const& rhs)noexcept{
    val += rhs.val;
    if(val>=MOD)val-=MOD;
    return *this;
  }
  constexpr mod_int &operator-=(mod_int const& rhs)noexcept{
    if(val<rhs.val)val+=MOD;
    val-=rhs.val;
    return *this;
  }
  constexpr mod_int &operator*=(mod_int const& rhs)noexcept{
    (val*=rhs.val)%=MOD;
    return *this;
  }
  constexpr mod_int &operator/=(mod_int rhs)noexcept{
    *this*=rhs.inverse();
    return *this;
  }
  constexpr bool operator==(mod_int const& rhs){
    return val==rhs.val;
  }
  constexpr bool operator!=(mod_int const& rhs){
    return !(val==rhs.val);
  }
  constexpr bool operator<(mod_int const& rhs){
    return val<rhs.val;
  }
  constexpr bool operator>(mod_int const& rhs){
    return val>rhs.val;
  }
  constexpr bool operator<=(mod_int const& rhs){
    return !(val>rhs.val);
  }
  constexpr bool operator>=(mod_int const& rhs){
    return !(val<rhs.val);
  }
  constexpr friend std::ostream &operator<<(std::ostream& os, mod_int const& mi){
    return os<<mi.val;
  }
  friend std::istream &operator>>(std::istream& is, mod_int & mi){
    ll t;is>>t;
    mi = mod_int<MOD>(t);
    return is;
  }
  constexpr mod_int inverse(){
    ll a=val,b=MOD,u=1,v=0,t;
    while(b>0){
      t=a/b;
      std::swap(a-=t*b,b);
      std::swap(u-=t*v,v);
    }
    return mod_int(u);
  }
  constexpr mod_int mpow(ll n){
    mod_int res(1),mul(val);
    while(n>0){
      if(n&1)res*=mul;
      mul*=mul;
      n>>=1;
    }
    return res;
  }
  constexpr friend  mod_int mpow(ll x,ll n){
    mod_int res(1),mul(x);
    while(n>0){
      if(n&1)res*=mul;
      mul*=mul;
      n>>=1;
    }
    return res;
  }
};
using mint = mod_int<1000000007>;

void solve1(){
  // https://atcoder.jp/contests/abc037/tasks/abc037_d
  int h,w;
  std::cin>>h>>w;
  std::vector<std::vector<mint>> a(h,std::vector<mint>(w));
  for(int i=0;i<h;++i)for(int j=0;j<w;++j){
    std::cin>>a[i][j];
  }
  std::vector<std::vector<mint>> dp(h,std::vector<mint>(w,-1));
  constexpr int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
  auto dfs = [&](auto&& dfs,int y,int x)->mint{
    if(dp[y][x]!=-1)return dp[y][x];
    mint res=1;
    for(int i=0;i<4;++i){
      int ny=y+dy[i],nx=x+dx[i];
      if(ny==-1||nx==-1||ny==h||nx==w)continue;
      if(a[ny][nx]<=a[y][x])continue;
      res += dfs(dfs,ny,nx);
    }
    return dp[y][x]=res;
  };
  mint ans=0;
  for(int i=0;i<h;++i)for(int j=0;j<w;++j){
    ans += dfs(dfs,i,j);
  }
  std::cout<<(ans)<<std::endl;
}

void solve2(){
  //https://atcoder.jp/contests/abc135/tasks/abc135_d
  std::string s;
  std::cin>>s;
  size_t n=s.size();
  std::vector<int> coef(n+1);
  coef[0]=1;
  for(size_t i=1;i<n;++i)coef[i]=coef[i-1]*10%13;
  std::vector<std::vector<mint>> dp(n+1,std::vector<mint>(13));
  dp[0][0]=1;
  for(size_t i=0;i<n;++i){
    if(s[i]=='?'){
      for(int j=0;j<10;++j)for(int k=0;k<13;++k){
        dp[i+1][(j*coef[n-i-1]+k)%13] += dp[i][k];
      }
    }else{
      int num = (s[i]-'0')*coef[n-i-1];
      for(int j=0;j<13;++j){
        dp[i+1][(num+j)%13] += dp[i][j];
      }
    }
  }
  std::cout<<(dp[n][5])<<std::endl;
}

main(){}