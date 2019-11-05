#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)

auto Z_algorithm(const string& s){
  ll n=s.size();
  vector<ll> z(n);
  z[0]=n;
  ll L=0,R=0;
  for(ll i=1;i<n;++i){
    if( i>R ){
      L=R=i;
      while( R<n && s[R-L]==s[R] )R++;
      z[i]=R-L;
      R--;
    }
    else{
      ll k=i-L;
      if( z[k]<R-i+1 )z[i]=z[k];
      else{
        L=i;
        while( R<n && s[R-L]==s[R] )R++;
        z[i]=R-L;
        R--;
      }
    }
  }
  return z;
}

main(){

  for(auto x:Z_algorythm("aababaaabaabaabbba"))cout<<x<<" ";
  cout<<endl;
  for(auto x:Z_algorythm("abcdabcdabcd"))cout<<x<<" ";
  cout<<endl;
  for(auto x:Z_algorythm("aaaaaaaaaaaaaa"))cout<<x<<" ";
  cout<<endl;
  for(auto x:Z_algorythm("abracadabra"))cout<<x<<" ";
  cout<<endl;
  for(auto x:Z_algorythm("ababa"))cout<<x<<" ";
  cout<<endl;
  for(auto x:Z_algorythm("abcabc"))cout<<x<<" ";
  cout<<endl;

}