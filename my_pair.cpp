#include<bits/stdc++.h>

template<class T=int,class U=int>
struct P{
  T t;
  U u;
  P(){}
  P(T _t,U _u):t(_t),u(_u){}
  constexpr void operator()(T _t,U _u){
    t = _t;
    u = _u;
  }
  constexpr P<T,U> operator+(P<T,U> const& rhs)const{
    return P<T,U>(t+rhs.t,u+rhs.u);
  }
  constexpr P<T,U> operator-(P<T,U> const& rhs)const{
    return P<T,U>(t-rhs.t,u-rhs.u);
  }
  constexpr P<T,U> &operator+=(P<T,U> const& rhs){
    t += rhs.t;
    u += rhs.u;
    return *this;
  }
  constexpr P<T,U> &operator-=(P<T,U> const& rhs){
    t -= rhs.t;
    u -= rhs.u;
    return *this;
  }
  constexpr P<T,U> &operator=(P<T,U> const& rhs){
    t = rhs.t;
    u = rhs.u;
    return *this;
  }
  constexpr bool operator==(P<T,U> const& rhs)const{
    return t==rhs.t&&u==rhs.u;
  }
  constexpr bool operator!=(P<T,U> const& rhs)const{
    return !(*this==rhs);
  }
  constexpr bool operator<(P<T,U> const& rhs)const{
    return t==rhs.t ? u<rhs.u : t<rhs.t;
  }
  constexpr bool operator<=(P<T,U> const& rhs)const{
    return t==rhs.t ? u<=rhs.u : t<=rhs.t;
  }
  constexpr bool operator>(P<T,U> const& rhs)const{
    return !(*this<=rhs);
  }
  constexpr bool operator>=(P<T,U> const& rhs)const{
    return !(*this<rhs);
  }
  constexpr std::pair<T,U> to_pair()const{
    return std::make_pair(t,u);
  }
  constexpr std::tuple<T,U> to_tuple()const{
    return std::make_tuple(t,u);
  }
};
template<class T,class U>
std::ostream &operator<<(std::ostream& os,P<T,U> const& p){
  os<<p.t<<" "<<p.u;
  return os;
}
template<class T,class U>
std::istream &operator>>(std::istream& is,P<T,U>& p){
  is>>p.t>>p.u;
  return is;
}

main(){
  P<> p(3,4);
  std::cout<<p<<std::endl;
  int a,b;
  std::cin>>a>>b;
  p(a,b);
  std::cout<<p<<std::endl;
}
