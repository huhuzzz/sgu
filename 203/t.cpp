#include <cstdio>
#include <cstdlib>
#define INF (1e9)
int main()
{
  freopen("in.txt","w",stdout);
  int n(500000);
  printf("%d\n",n);
  for(int i=0;i<n;++i)
    printf("%d ",(rand()%(int)INF+1));
  return 0;
}
