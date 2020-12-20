#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
//#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
//#define abs(x) ((x<0)?(-(x)):(x))
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x){return mrand()%x;}
ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
#define rank oiajgpowsdjg
//head
const int _n=65536+10;
struct WE{int val,cnt;
bool operator<(const WE& rhs)const{return cnt>rhs.cnt;}};
WE w1[_n],w2[_n];
FILE *RF1, *RF2;
wchar_t t,first1,first2;
int c1,c2,R1[_n],R2[_n],n=(1<<16),cnt,cnt2;
int main(int argc, char **argv) {//cin.tie(0);ios_base::sync_with_stdio(0);
  locale::global(locale(""));
  if((RF1=fopen(argv[1], "r"))==NULL){
    wcout<<L"第一篇文章開不起來\n";
    return 0;
  }
  if((RF2=fopen(argv[2], "r"))==NULL){
    wcout<<L"第二篇文章開不起來\n";
    return 0;
  }
  rep(w,0,n)w1[w].val=w,w2[w].val=w;
  while(fwscanf(RF1,L"%lc",&t)==1){
    if(!first1)first1=t;
    c1++;w1[(int)t].cnt++;
  }
  while(fwscanf(RF2,L"%lc",&t)==1){
    if(!first2)first2=t;
    c2++;w2[(int)t].cnt++;
  }
  //反註解這行可以先確認兩篇文章第一個字一樣(也就是編碼一樣)
  //assert((int)first1==(int)first2);
  sort(w1,w1+n),sort(w2,w2+n);
  rep(i,0,n)R1[w1[i].val]=i; rep(i,0,n)R2[w2[i].val]=i;
  db Z=0;
  db D=0;rep(w,0,n){
    db pi=(1.0*w1[R1[w]].cnt)/(1.0*c1);
    db pj=(1.0*w2[R2[w]].cnt)/(1.0*c2);
    if(pi>1e-8)pi=-pi*log(pi);
    else pi=0;
    if(pj>1e-8)pj=-pj*log(pj);
    else pj=0;
    assert(!(pi<0) and !(pj<0));
    if(fabs(pi+pj)>1e-8)cnt++;
    //ONLY CONSIDER SHARED WORDS
    if(pi>1e-8 and pj>1e-8)cnt2++,Z+=pi+pj,D+=fabs(R1[w]-R2[w])*1.0*(pi+pj);
  }
  assert(D>=0);
  if(Z>0)D/=(Z*1.0*cnt2);
  else wcout<<L"某篇文章可能太短了\n";
  wcout<<L"兩篇文章的距離：";
  wcout<<scientific<<setprecision(4)<<D<<'\n';
  wcout<<L"第一篇文章的字數："<<c1<<'\n';
  wcout<<L"第二篇文章的字數："<<c2<<'\n';
  wcout<<L"總共出現的字的種類數："<<cnt<<'\n';
  wcout<<L"兩篇文章都有使用的字的種類數："<<cnt2<<'\n';
  return 0;
}