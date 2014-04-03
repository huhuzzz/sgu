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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 20000 + 7;
ll light[N][4];
const ll base = (ll)1e11;
bool in[N];
int g( ll ansV, vector<int> &r, int n )
{
  r.resize(0);
  for( int i = 0; i < n; ++i )
    {
      if( ansV * light[i][3] < light[i][0] * base )
	{
	  if( ansV * ( light[i][1] + light[i][3] ) >= light[i][0] * base )
	    {
	      r.push_back(i);
	    }
	  else
	    {
	      // ll tmp = ( light[i][3] + light[i][1] ) *
	      // 	ansV - light[i][0] * base;
	      ll tmpB = light[i][0] * base - ( light[i][3] + light[i][1] ) * 
		ansV;
	      tmpB %= ( ( light[i][1] + light[i][2] ) * ansV );
	      if( tmpB == 0 || tmpB > light[i][2] * ansV )
		{
		  r.push_back(i);
		}
	    }
	}
    }
  return r.size();
}
int main()
{
  int n, s;
  ll vMin, vMax;
  cin >> n >> s >> vMin >> vMax;
  assert( n < N );
  multimap<ll, int, greater<ll> > mapp;
  for(int i = 0; i < n; ++i )
    {
      int x, r, g, d;
      scanf("%d%d%d%d", &x, &r, &g, &d);
      light[i][0] = x , light[i][1] = r, light[i][2] = g, light[i][3] = d;
      ll k = 0;
      if( light[i][0] <= light[i][3] * vMax )
	{
	  mapp.insert( make_pair( vMax * base, i + 1 ) );
	  mapp.insert( make_pair( max( ( light[i][0] * base + light[i][3] - 1 )  / 
				       light[i][3], vMin ), - i - 1 ) );
	}
      // else if( light[i][0] > ( light[i][3] + light[i][1] ) * vMax )
      // 	{
      // 	  k = ( light[i][0] - ( light[i][3] + light[i][1] ) * vMax ) /
      // 	    ( ( light[i][1] + light[i][2] ) * vMax ) ;
      // 	}
      for( ; ; ++k )
	{
	  ll t = light[i][3] + light[i][1] + ( light[i][1] + light[i][2] ) * k;
	  ll v1B = light[i][0] * base / t;
	  ll v2B = ( light[i][0] * base + t + light[i][2] - 1 ) / ( t + light[i][2] );
	  // v2B = min( v2B, v1B );
	  if( v1B < vMin * base )
	    break;
	  if( v2B <= vMax * base )
	    {
	      mapp.insert( make_pair( min( max( v1B - 1, vMin * base ), vMax * base ), i + 1) );
	      mapp.insert( make_pair( max( v2B, vMin * base ) , - i - 1 ) );
	    }
	}
      // ld t = light[i][0] / (ld) vMax;
      // int k = 0;
      // if( t <= light[i][3] - eps )
      // 	{
      // 	  mapp.insert( make_pair( vMax, 1 ) );
      // 	  mapp.insert( make_pair( (ld)light[i][0] / (ld)light[i][3], - 1 ) );
      // 	}
      // else if( t > light[i][3] + light[i][1] )
      // 	{
      // 	  t -= light[i][3] + light[i][1];
      // 	  k = ( t + det ) / ( light[i][1] + light[i][2] );
      // 	}
      // for( ;; ++k)
      // 	{
      // 	  ld t = light[i][3] + light[i][1] + ( light[i][1] + light[i][2] ) * (ld)k;
      // 	  ld vb = (ld)light[i][0] / t;
      // 	  ld ve = (ld)light[i][0] / ( t + light[i][2] );
      // 	  if( vb <= vMin - eps )
      // 	    break;
      // 	  if( ve <= vMax - eps )
      // 	    {
      // 	      mapp.insert( make_pair( min( vb, (ld)vMax), 1 ) );
      // 	      mapp.insert( make_pair( max( ve, (ld)vMin), -1 ) );
      // 	    }
      // 	}
    }
  int ans(0), pre(0);
  ll ansV = vMax * base;
  for( ; !mapp.empty(); )
    {
      ll v = mapp.begin()->first;
      vector<int> add, sub;
      for(; !mapp.empty() && mapp.begin()->first == v; )
	{
	  int tmp = mapp.begin()->second;
	  if( tmp > 0 )
	    {
	      add.push_back(tmp);
	      assert( in[tmp] == false );
	      in[tmp] = true;
	    }
	  else if( tmp < 0 )
	    {
	      sub.push_back( - tmp);
	    }
	  mapp.erase( mapp.begin() );
	}
      if( ans < pre + add.size() )
	{
	  ans = pre + add.size();
	  ansV = v;
	}
      pre += add.size() - sub.size();
      for( int i = 0; i < sub.size(); ++i )
	{
	  assert( in[sub[i]] );
	  in[sub[i]] = false;
	}
    }
  assert( pre == 0 );
  assert( ansV <= vMax * base && ansV >= vMin * base );
  // vector<int> aa;
  // int t = g( ansV, aa, n );
  // ll z = ansV;
  // for(int i = 1; i < 20 && ansV + i <= vMax * base; ++i )
  //   if( t >= g( ansV + i * 10, aa, n ) )
  //     z = ansV + i * 10;
  // for( int i = 1; i < 20 && ansV - i >= vMin * base; ++i )
  //   if( t > g( ansV - i * 10, aa, n ) )
  //     z = ansV - i * 10;
  // printf("%.10lf\n%d\n", (double)z / (double) base, g( z, aa, n ) );
  // for( int i = 0; i < aa.size(); ++i )
  //   printf("%d ", aa[i] + 1 );
  // assert( n - ans == cnt );
  vector<int> aa;
  assert( n - ans == g( ansV, aa, n ) );
  printf("%.10lf\n%d\n", (double)ansV / (double)base, n - ans );
  for( int i = 0; i < aa.size(); ++i )
    printf("%d ", aa[i] + 1 );
  return 0;
}
