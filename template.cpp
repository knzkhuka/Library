#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = long long;
constexpr ll INF = (1LL<<60);
constexpr ll MOD = (1e9+7);
constexpr double PI = acos(-1);
constexpr double EPS = (1e-7);
template<typename T>T gcd(T a,T b){while(1){swap(a,b);if(a==0)return b;if(b==0)return a;a%=b;}}
template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
inline void dump(){cout<<endl;}
template<class Head,class... Tail>inline void dump(Head&& head, Tail&&... tail){cout<<head<<", ";dump(forward<Tail>(tail)...);}
template<typename T>inline istream &operator>>(istream&input,vector<T>&v){for(auto &elemnt:v)input>>elemnt;return input;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
using vertex = struct vertex{ll to,cost;vertex(ll to,ll cost):to(to),cost(cost){}};
using edge = struct edge{ll from,to,cost;edge(ll from,ll to,ll cost):from(from),to(to),cost(cost){}};
using weighted_adjlist = vector<vector<vertex>>;
using weighted_edge = vector<edge>;
struct pos{
  int y,x;
  pos(){}
  pos(int _y,int _x):y(_y),x(_x){}
  pos operator+(pos const& a){
    return pos(y+a.y,x+a.x);
  }
  pos operator-(pos const& a){
    int _y=y-a.y;
    int _x=x-a.x;
    return pos(_y,_x);
  }
  pos& operator+=(pos const& a){
    x+=a.x;y+=a.y;
    return (*this);
  }
  pos& operator-=(pos const& a){
    y-=a.y;
    x-=a.x;
    return *this;
  }
  pos& operator=(pos const& a){x=a.x;y=a.y;return (*this);}
  bool operator==(pos const& rhs)const{
    return y==rhs.y&&x==rhs.x;
  }
  bool operator!=(pos const& rhs)const{
    return !(y==rhs.y&&x==rhs.x);
  }
  bool operator<(pos const& rhs)const{
    return y<rhs.y;
  }
  bool operator>(pos const& rhs)const{
    return y>rhs.y;
  }
};
template<ll MOD=ll(1e9+7)>
ll mod_pow(ll n,ll p){
  ll ans=1LL;
  while(p){
    if(p&1)ans*=n;
    n*=n;
    p>>=1;
    ans%=MOD;
    n%=MOD;
  }
  return ans;
}
double rad_to_deg(double n){
  return n*180.0/PI;
}
double deg_to_rad(double n){
  return n*PI/180.0;
}

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  

}