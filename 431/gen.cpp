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

int main()
{
  int n=2,m=2;
  cout<<n<<' '<<m<<endl;
  srand(time(NULL));
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<5;++j)
	printf("%c",((rand()%('e'-'a')+'a')));
      printf("\n");
    }
  for(int i=0;i<m;++i)
    {
      for(int j=0;j<5;++j)
	printf("%c",((rand()%('e'-'a')+'a')));
      printf("\n");
    }
  return 0;
}
