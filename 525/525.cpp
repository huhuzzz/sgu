#include <cstdio>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1007
#define M 20007
typedef long long ll;
int p[M+1][3],poi;
int s[N];
int d[N];
int id;
bool in[N];
int low[N];
int sta[N],sti;
int grp;
int bel[N];
int num[N];

int q[M][2],qoi;
int sq[N];
int du[N];
int dur[N];
int q1[N];
//int dis[N];
int r[M][2],ri,sr[N];
int ans[M],ani;
const int B=6;
const int msk=((1<<B)-1);
ll con[N][(N+msk)>>B];
ll rch[N][(N+msk)>>B];
ll rchr[N][(N+msk)>>B];
int nn[N][N];
void dfs(int v)
{
  /*
  sta[sti++]=v;
  d[v]=++id;
  int r=id;
  for(int i=s[v];i;i=p[i][1])
    {
      int t=p[i][0];
      if(bel[t]==0)
	{
	  if(d[t]==0)
	    dfs(t,1+l);
	  d[v]=min(d[t],d[v]);
	}
    }
  if(d[v]==r)
    {
      ++grp;
      for(;;)
	{
	  int vv=sta[--sti];
	  ++num[grp-1];
	  bel[vv]=grp;
	  if(vv==v)
	    break;
	}
	}*/
  in[v]=true;
  d[v]=low[v]=++id;
  sta[sti++]=v;
  for(int i=s[v];i;i=p[i][1])
    if(d[p[i][0]]==0)
      {
	dfs(p[i][0]);
	low[v]=min(low[v],low[p[i][0]]);
      }
    else if(in[p[i][0]])
      low[v]=min(low[v],low[p[i][0]]);
  if(d[v]==low[v])
    {
      for(;sti>0;)
	{
	  --sti;
	  in[sta[sti]]=false;
	  bel[sta[sti]]=grp;
	  ++num[grp];
	  if(sta[sti]==v)
	    break;
	}
      ++grp;
    }
}
void bfs(int bdu[],ll brch[][(N+msk)>>B],int bsr[],int br[][2])
{
  int f1,l1;
  f1=l1=0;
  for(int i=0;i<grp;++i)
    {
      if(bdu[i]==0)
	q1[l1++]=i;
      brch[i][i>>B]|=((ll)1<<(i&msk));
    }
  for(;f1<l1;++f1)
    {
      int v=q1[f1];
      for(int i=bsr[v];i;i=br[i][1])
	{
	  int t=br[i][0];
	  if(0==--bdu[t])
	    q1[l1++]=t;
	  for(int l=0;l<((msk+grp)>>B);++l)
	    brch[t][l]|=brch[v][l];
	}
    }
}
int main()
{
  freopen("in.txt","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      --f,--t;
      ++poi,p[poi][0]=t,p[poi][1]=s[f],p[poi][2]=i+1,s[f]=poi;
    }
  for(int i=0;i<n;++i)
    if(d[i]==0)
      dfs(i);
  //for(int i=0;i<n;++i)
  //--bel[i];
  for(int i=0;i<n;++i)
    {
      int a=bel[i];
      for(int j=s[i];j;j=p[j][1])
	{
	  int b=bel[p[j][0]];
	  if(a!=b && !(con[a][b>>B]&((ll)1<<(b&msk))))
	    {
	      con[a][b>>B]|=((ll)1<<(b&msk));
	      ++qoi,q[qoi][0]=b,q[qoi][1]=sq[a],sq[a]=qoi;
	      ++du[a];
	      ++dur[b];
	      ++ri,r[ri][0]=a,r[ri][1]=sr[b],sr[b]=ri;
	    }
	}
    }
  bfs(du,rch,sr,r);
  bfs(dur,rchr,sq,q);
  int w(1);
  for(int i=0;i<n;++i)
    {
      int a=bel[i];
      for(int j=s[i];j;j=p[j][1])
	{
	  int b=bel[p[j][0]];
	  int tmp;
	  if(nn[a][b])
	    tmp=nn[a][b];
	  else
	    {
	      tmp=0;
	      for(int l=0;l<grp;++l)
		if((rchr[l][a>>B]&((ll)1<<(a&msk))) && (rch[l][b>>B]&((ll)1<<(b&msk))))
		  tmp+=num[l];
	      nn[a][b]=tmp;
	    }
	  if(tmp>=w)
	    {
	      if(tmp>w)
		ani=0,w=tmp;
	      ans[ani++]=p[j][2];
	    }
	}
    }
  printf("%d\n%d\n",w,ani);
  for(int i=0;i<ani;++i)
    printf("%d ",ans[i]);
  return 0;
}
