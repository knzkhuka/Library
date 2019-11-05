#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)

constexpr ll COM_MAX = (ll)1e6;
vector<ll> fac(COM_MAX),finv(COM_MAX),inv(COM_MAX);
// 前処理
void comb_init(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<COM_MAX;++i){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
// 二項係数計算
ll comb(ll n,ll k){
  if(n<k)return 0;
  if(n<0||k<0)return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
// 重複組み合わせ
ll nHk(ll n,ll k){
  return comb(n+k-1,n-1);
}

std::vector<ll> divisor(ll n){
  std::vector<ll> div;
  for(ll p=1;p*p<=n;++p){
    if(n%p==0){
     div.push_back(p);
     if(p*p!=n)div.push_back(n/p);
    }
  }
  std::sort(div.begin(),div.end());
  return div;
}

std::vector<std::pair<ll,ll>> prime_factorization(ll n){
  std::vector<std::pair<ll,ll>> factor;
  for(ll p=2;p*p<=n;++p){
    if(n%p!=0)continue;
    ll num=0;
    while(n%p==0){
      num++;
      n/=p;
    }
    factor.emplace_back(p,num);
    if(n==1)return factor;
  }
  if(n!=1)factor.emplace_back(n,1);
  return factor;
}

using Real = long double;
using Complex = complex<Real>;
constexpr Real PI = (Real)acos(-1);

vector<Complex> DFT(vector<Complex> a){
  ll n = a.size();
  if(n==1)return a;
  vector<Complex> a0(n/2);
  vector<Complex> a1(n/2);
  rep(i,n/2)a0[i]=a[i*2];
  rep(i,n/2)a1[i]=a[i*2+1];
  vector<Complex> inversed_a0 = DFT(a0);
  vector<Complex> inversed_a1 = DFT(a1);
  vector<Complex> inversed_a(n);
  rep(i,n){
    Complex zeta_n_i = Complex( cos(2*PI*i/n),sin(2*PI*i/n) );
    inversed_a[i] = inversed_a0[i%(n/2)]+zeta_n_i*inversed_a1[i%(n/2)];
  }
  return inversed_a;
}
vector<Complex> IDFT(vector<Complex> inversed_a){
  ll n = inversed_a.size();
  vector<Complex> arranged = DFT(inversed_a);
  vector<Complex>swaped(n);
  rep(i,n)swaped[i]=arranged[(n-i)%n];
  vector<Complex> a(n);
  rep(i,n)a[i]=swaped[i]/Complex(n,0);
  return a;
}
vector<Complex> conv(vector<Complex> a,vector<Complex> b){
  ll deg = a.size()+b.size()-1;
  ll n = 1;
  while(n<deg)n<<=1;
  a.resize(n);b.resize(n);
  vector<Complex> inversed_c(n);
  vector<Complex> inversed_a = DFT(a);
  vector<Complex> inversed_b = DFT(b);
  rep(i,n){
    inversed_c[i] = inversed_a[i]*inversed_b[i];
  }
  vector<Complex> c = IDFT(inversed_c);
  return c;
}

main(){


}