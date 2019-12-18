#include<iostream>
#include<vector>

template<class T,class F>
struct segtree{
  int n;
  T e;
  F f;
  std::vector<T> dat;

  segtree(){}
  segtree(T _e,F _f):e(_e),f(_f){}
  segtree(std::vector<T> const& v,T _e,F _f):e(_e),f(_f){
    build(v);
  }
  void build(std::vector<T> const& v){
    n = 1;
    int sz = v.size();
    while(n<=sz)n<<=1;
    dat.resize(2*n,e);
    for(int i=0;i<sz;++i){
      dat[i+n] = v[i];
    }
    for(int i=n-1;i>0;--i){
      dat[i] = f(dat[i<<1],dat[i<<1|1]);
    }
  }
  void modify(int p,T v){
    for(dat[p+=n]+=v;p>1;p>>=1){
      dat[p>>1] = f(dat[p],dat[p^1]);
    }
  }
  // [l,r)
  T query(int l,int r){
    T res = e;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
      if(l&1){
        res = f(res,dat[l]);
        l++;
      }
      if(r&1){
        r--;
        res = f(res,dat[r]);
      }
    }
    return res;
  }
};

int main(){}

void RSQ(){

  int n,q;
  std::cin>>n>>q;

  std::vector<int> emp(n);
  auto sum = [](auto a,auto b){return a+b;};
  segtree<int,decltype(sum)> seg(emp,0,sum);

  while(q--){
    int com,x,y;
    std::cin>>com>>x>>y;
    if(com){
      x--;y--;
      std::cout<<seg.query(x,y+1)<<std::endl;
    }else{
      x--;
      seg.modify(x,y);
    }
  }


}