<<<<<<< HEAD
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
#define M 10007
#define N 1007
#define R 1007
const ing inf=1e9+7;
// struct edge
// {
//   int to,cost,id;
//   edge(int t,int c,int i){to=t,cost=c,id=i;};
// };
int n,m,r,S,T;
vector<int> p[N],pp[N];
vector<int> q[R];
vector<int> u[M];
int ed[M][3];
vector<int> dis[M];
void add(int f,int t,int c,int id)
{
  ed[id][0]=f,ed[id][1]=t,ed[id][2]=c;
  p[f].PB(t);
  pp[t].PB(f);
}
int main()
{
  scanf("%d%d%d%d%d",&n,&m,&r,&s,&t);
  FOR(i,0,m)
    {
      int f,t,c;
      scanf("%d%d%d",&f,&t,&c);
      add(f,t,c,i+1);
    }
  add(0,s,0,m+1);
  FOR(i,0,r)
    {
      int k;
      scanf("%d",&k);
      FOR(j,0,k)
	{
	  int c;
	  scanf("%d",&c);
	  q[i].PB(c);
	  u[c].PB(i);
	}
    }
  FOR(i,1,m+1)
    {
      sort(u[c].begin(),u[c].end());
      dis[i].resize(1<<(u[c].size()));
      fill(dis[i].begin(),dis[i].end(),inf);
    }
  if(dfs(s,t))
    {
      dis[m+1][0]=0;
      queue<ppi> que;
      que.PB(ppi(m+1,0));
      for(;!que.empty();que.pop())
	{
	  int v=que.front().FIR;
	  int e=que.front().SEC;
	  
	}
=======
#include <map>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
#define N 1007
#define M 10007
#define R 1007
int n,m,r,S,T,ss;
int edge[M][3];
vector<int> in[N],out[N];
// vector<int> sp[R];
int bonus[R];
int begmsk[M];
vector<int> road[M];
vector<pair<int,int> > trs[M];
vector<pair<int,int> > end[M];
int tag[R][3];
vector<int> dis[M];
vector<int> inque[M];
const int inf=1e9;
bool vis[N];
bool bfs(int from,int to)
{
  queue<int> que;
  vis[from]=true;
  que.push(from);
  for(;!que.empty();)
    {
      int v=que.front();
      que.pop();
      for(int i=0;i<out[v].size();++i)
	{
	  int id=out[v][i];
	  int vv=edge[id][1];
	  if(!vis[vv])
	    {
	      que.push(vv);
	      vis[vv]=true;
	    }
	}
    }
  return vis[to];
}
void prt(int id,int msk,int num)
{
  if(id!=m+1)
    {
      int info=inque[id][msk]>>1;
      prt(info>>10,info&((1<<10)-1),num+1);
      printf("%d ",id);
    }
  else printf("%d\n",num);
}
void add(int f,int t,int c,int idx)
{
  edge[idx][0]=f,edge[idx][1]=t,edge[idx][2]=c;
  out[f].push_back(idx);
  in[t].push_back(idx);
}
int main()
{
  scanf("%d%d%d%d%d",&n,&m,&r,&S,&T);
  for(int i=0;i<m;++i)
    {
      int from,to,cost;
      scanf("%d%d%d",&from,&to,&cost);
      add(from,to,cost,i+1);
    }
  for(int i=0;i<r;++i)
    {
      int k;
      scanf("%d",&k);
      // sp[i].resize(k);
      int sum=0;
      for(int j=0;j<k;++j)
	{
	  int e;
	  scanf("%d",&e);
	  // sp[i][j]=e;
	  if(j==0)
	    begmsk[e]|=(1<<(road[e].size()));
	  road[e].push_back(i);
	  sum+=edge[e][2];
	}
      bonus[i]=sum;
    }
  ss=n+1;
  add(ss,S,0,m+1);
  for(int i=1;i<=ss;++i)
    {
      for(int j=0;j<out[i].size();++j)
	{
	  int id=out[i][j];
	  int to=edge[id][1];
	  for(int k=0;k<road[id].size();++k)
	    {
	      int ri=road[id][k];
	      tag[ri][0]=i;
	      tag[ri][1]=j;
	      tag[ri][2]=1<<k;
	    }
	}
      for(int j=0;j<in[i].size();++j)
	{
	  int id=in[i][j];
	  int from=edge[id][0];
	  for(int k=0;k<road[id].size();++k)
	    {
	      int ri=road[id][k];
	      if(tag[ri][0]==i)
		{
		  trs[id].push_back(make_pair(tag[ri][1],tag[ri][2]));
		}
	      else
		{
		  trs[id].push_back(make_pair(-1,-1));
		  end[id].push_back(make_pair(1<<k,bonus[ri]));
		}
	    }
	}
    }
  for(int i=1;i<=m+1;++i)
    {
      dis[i].resize(1<<road[i].size());
      inque[i].resize(1<<road[i].size());
      fill(dis[i].begin(),dis[i].end(),inf);
    }
  if(bfs(ss,T))
    {
      int ans=inf;
      int mtag,idtag;
      dis[m+1][0]=0;
      queue<int>que;
      que.push((m+1)<<10);
      inque[m+1][0]=1;
      for(;!que.empty();)
	{
	  int id=que.front()>>10;
	  int msk=que.front()&((1<<10)-1);
	  que.pop();
	  inque[id][msk]^=1;
	  int v=edge[id][1];
	  int m[10]={0};
	  for(int i=1,j=0;i<=msk;i<<=1,++j)
	    if(i&msk)
	      {
		if(trs[id][j].first>=0)
		  {
		    m[trs[id][j].first]|=trs[id][j].second;
		  }
	      }
	  for(int i=0;i<out[v].size();++i)
	    {
	      int tid=out[v][i];
	      int to=edge[tid][1];
	      int mm=m[i]|begmsk[tid];
	      int len=dis[id][msk]+edge[tid][2];
	      for(int j=0;j<end[tid].size();++j)
		{
		  if(end[tid][j].first&mm)
		    {
		      len+=end[tid][j].second;
		      mm^=end[tid][j].first;
		    }
		}
	      assert(len<inf && len>=0);
	      if(len<ans)
		{
		  if(len<dis[tid][mm])
		    {
		      dis[tid][mm]=len;
		      bool in_que=inque[tid][mm]&1;
		      inque[tid][mm]=(((id<<10)|msk)<<1);
		      if(!in_que)
			{
			  if(to==T)
			    {
			      ans=len;
			      mtag=mm;
			      idtag=tid;
			    }
			  else
			    {
			      que.push((tid<<10)|mm);
			      inque[tid][mm]|=1;
			    }
			}
		    }
		}
	    }
	}
      printf("%d\n",ans);
      prt(idtag,mtag,0);
>>>>>>> cb63a78251aab44fcee403f73f8b8cf42a514f40
    }
  else printf("-1");
  return 0;
}