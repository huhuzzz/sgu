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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 30;
char s[2][N];
vector<char> ans;
int seq[N + 'A'];
int n;
void cal( char * f, char * t )
{
  char tmp[N];
  memcpy( tmp, f, n);
  int cc=0;
  for( int i = 0; i < n; ++i )
    {
      char z[N];
      memcpy( z, t, n );
      for( int j = 0 ; j < n; ++j )
	seq[tmp[j]] = j;
      // z[n] = tmp[n] = 0;
      // cout << z << ' ' << tmp << endl;
      vector<char> a;
      for( int j = n - 1; j >= 0; --j )
	a.push_back( z[j] );
      for( ; ; )
	{
	  int j = n - 1;
	  int last = n ;
	  bool ok = false;
	  for( ; j >= 0; --j )
	    {
	      int kk = 0;
	      for( ; kk < n; ++kk )
		if( a[a.size() - 1 - kk] != f[kk] )
		  break;
	      if( kk >= n )
		{
		  ok = true;
		  break;
		}
	      // for( kk = 0 ; kk < n ; ++kk )
	      // 	cout << a[ a.size() - 1 - kk ] ;
	      // cout << endl;
	      // cout << z << ' ' << tmp << ' '<<i << endl;
	      // ++cc;
	      // if( cc > 2 )
	      // 	  return;

	      // int id = j;
	      // for( int jj = j - 1; jj >= 0; --jj )
	      // 	if( seq[ z[id] ] < seq[ z[jj] ] )
	      // 	  id = jj;

	      // // if( i == 3 )
	      // // 	cout << "!" << id << ' ' << j << endl;
	      // for( int k = id; k < j; ++k )
	      // 	swap( z[k], z[k + 1] );
	      // for( int k = j; k >= id; --k )
	      // 	a.push_back( z[k] );
	      // j = id;

	      int rj = j;
	      if( z[j] != tmp[j] )
	      	{
	      	  for( int k = j - 1; k >= 0; --k)
	      	    {
	      	      if( z[k] == tmp[j] )
	      		{
	      		  for( int kk = k; kk < j; ++kk )
	      		    {
	      		      swap( z[kk], z[kk + 1]);
	      		    }
	      		  j = k;
	      		  break;
	      		}
	      	    }
	      	}
	      for( ; rj >= j; --rj )
	      	a.push_back( z[rj] );
	    }
	  if( ok )
	    break;
	  // for( int j = n - 1; j >= 0; --j )
	  //   a.push_back( z[j] );
	  // j = 0;
	  // for( ; j < n; ++j )
	  //   if( z[j] != tmp[j] )
	  //     break;
	  // if( j >= n )
	  //   break;
	}
      // for( int j = n - 1 ; ( a.size() % n ) != i; --j )
      // 	a.push_back( z[j] );
      // if( i == 3 )
      // 	{
      // 	  cout << tmp << endl;
      // 	  for( int j = a.size() - 1; j >= 0; --j )
      // 	    cout << a[j];
      // 	  cout << endl;
      // 	}
      if( ans.empty() || ans.size() > a.size() )
	{
	  ans = a;
	  // cout << i << endl;
	}
      for( int j = 0 ; j < n - 1 ; ++j )
	swap( tmp[j], tmp[j + 1] );
    }
}
int main()
{
  scanf("%d%s%s", &n, s[0], s[1] );
  if( n > 7 )
    return 1;
  cal( s[0], s[1]);
  cal( s[1], s[0]);
  // reverse( ans.begin(), ans.end() );
  cout << ans.size() << endl;
  for( int i = ans.size() - 1; i >= 0; --i )
    printf("%c", ans[i] );
  // printf("%s", a < b ? bak : ans);
  return 0;
}
