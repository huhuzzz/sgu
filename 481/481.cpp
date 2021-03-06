#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 5007
const ll base=1e9;
vector<int> a[N],b[N];
typedef complex<double> cpx;
const double pi=acos(-1.0);
const double eps=1e-6;
void pt(vector<int> &a)
{
  if(a.size()>0)
    {
      int i=a.size()-1;
      printf("%d",a[i]);
      for(--i;i>=0;--i)
	printf("%09d",a[i]);
    }
  else printf("0");
}
void add(vector<int> &a,vector<int> &b)
{
  int l=max(b.size(),a.size());
  for(int i=0;i<l;++i)
    {
      if(i>=a.size())
	a.resize(i+1);
      ll tmp=a[i];
      if(i<b.size())
	tmp+=b[i];
      a[i]=tmp%base;
      tmp/=base;
      if(tmp>0)
	{
	  if(a.size()<=i+1)
	    a.resize(i+2);
	  a[i+1]+=tmp;
	}
    }
}
void mul(vector<int> &a,ll c)
{
  vector<int> tmp=a;
  a.resize(0);
  for(int i=0;i<tmp.size();++i)
    {
      if(a.size()<=i)
	a.resize(i+1);
      ll z=c*(ll)tmp[i]+(ll)a[i];
      a[i]=z%base;
      z/=base;
      if(z>0)
	{
	  if(a.size()<=i+1)
	    a.resize(i+2);
	  a[i+1]+=z;
	}
    }
}
int main()
{
  // freopen("in","r",stdin);
  // freopen("o2","w",stdout);
  int n;
  scanf("%d",&n);
  vector<int> a,ans;
  a.push_back(1);
  for(int i=3;i<n;++i)
    {
      mul(ans,n);
      add(ans,a);
      mul(a,n-i);
    }
  mul(ans,n*(n-1)/2);
  mul(ans,n-2);
  mul(a,(n-1)*(n-2)/2);
  add(ans,a);
  pt(ans);
  return 0;
}
