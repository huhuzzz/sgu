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
#define N 307
#define M 307
//pawn, rook, knight, bishop, queen, and king
int p[7];
char q[N][M];
int cnt[N][M];
bool cg[N][M];
int rx,ry;
int n,m;
bool inr(int x,int y)
{
  return (x<n && x>=0 && y<m && y>=0);
}
int score[255];
void calp(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  if(inr(x-1,y-1))
    {
      c[x-1][y-1]+=num;
      if(c[x-1][y-1]==0)
	que.push(ppi(x-1,y-1));
    }
  if(inr(x-1,y+1))
    {
      c[x-1][y+1]+=num;
      if(c[x-1][y+1]==0)
	que.push(ppi(x-1,y+1));
    }
}
void calm(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,-1,2)
    FOR(j,-1,2)
    if(i!=0 || j!=0)
      {
	int xx=x+i,yy=y+j;
	if(inr(xx,yy))
	  {
	    c[xx][yy]+=num;
	    if(c[xx][yy]==0)
	      que.push(ppi(xx,yy));
	  }
      }
}
const static int dirq[][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
void calq(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,0,8)
    for(int xx=x+dirq[i][0],yy=y+dirq[i][1];inr(xx,yy);xx+=dirq[i][0],yy+=dirq[i][1])
      {
	c[xx][yy]+=num;
	if(c[xx][yy]==0)
	  que.push(ppi(xx,yy));
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
const static int dirb[][2]={{1,1},{-1,-1},{1,-1},{-1,1}};
void calb(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,0,4)
    for(int xx=x+dirb[i][0],yy=y+dirb[i][1];inr(xx,yy);xx+=dirb[i][0],yy+=dirb[i][1])
      {
	c[xx][yy]+=num;
	if(c[xx][yy]==0)
	  que.push(ppi(xx,yy));
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
const static int dirk[][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
void calk(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,0,8)
    {
      int xx=x+dirk[i][0],yy=y+dirk[i][1];
      if(inr(xx,yy))
	{
	  c[xx][yy]+=num;
	  if(c[xx][yy]==0)
	    que.push(ppi(xx,yy));
	}
    }
}
const static int dirr[][2]={{1,0},{-1,0},{0,1},{0,-1}};
void calr(int x,int y,int c[N][M],int num,queue<ppi> &que)
{
  FOR(i,0,4)
    for(int xx=x+dirr[i][0],yy=y+dirr[i][1];inr(xx,yy);xx+=dirr[i][0],yy+=dirr[i][1])
      {
	c[xx][yy]+=num;
	if(c[xx][yy]==0)
	  que.push(ppi(xx,yy));
	if(q[xx][yy]!='.' && q[xx][yy]!='@')
	  break;
      }
}
int uncal(int x,int y,int c[N][M],queue<ppi> &que)
{
  switch(q[x][y])
    {
    case 'P':
      calp(x,y,c,-1,que);
      return p[0];
    case 'R':
      calr(x,y,c,-1,que);
      return p[1];
    case 'K':
      calk(x,y,c,-1,que);
      return p[2];
    case 'B':
      calb(x,y,c,-1,que);
      return p[3];
    case 'Q':
      calq(x,y,c,-1,que);
      return p[4];
    case 'M':
      calm(x,y,c,-1,que);
      return p[5];
    default:
      //assert(0);
      break;
    }
  return 0;
}
void cal(int x,int y,int c[N][M])
{
  queue<ppi> qq;
  switch(q[x][y])
    {
    case '@':
      rx=x,ry=y;
      break;
    case 'P':
      calp(x,y,c,1,qq);
      break;
    case 'R':
      calr(x,y,c,1,qq);
      break;
    case 'K':
      calk(x,y,c,1,qq);
      break;
    case 'B':
      calb(x,y,c,1,qq);
      break;
    case 'Q':
      calq(x,y,c,1,qq);
      break;
    case 'M':
      calm(x,y,c,1,qq);
      break;
    case '#':
    case '.':
      break;
    default:
      assert(0);
      break;
    }
}
bool add(int x,int y,int z[N][M],int count[N][M],queue<ppi> &que)
{
  int rz=z[x][y];
  if(z[x][y]==0 && count[x][y]==0 && q[x][y]!='#')
    {
      que.push(ppi(x,y)),z[x][y]=1;
      //return (q[x][y]=='.' || q[x][y]=='@');
    }
  if(q[x][y]!='#')
    cg[x][y]=true;
  return q[x][y]!='#' && rz==0 && (q[x][y]=='.' || q[x][y]=='@');//*
}
void fill(int x,int y,int z[N][M],int count[N][M],queue<ppi> &que,int queen)
{
  if(queen)
    {
      for(int k=0;k<8;++k)
	for(int i=x+dirq[k][0],j=y+dirq[k][1];inr(i,j) && add(i,j,z,count,que);i+=dirq[k][0],j+=dirq[k][1])
	  ;
    }
  else
    {
      FOR(i,0,8)
	{
	  int xx=x+dirk[i][0],yy=y+dirk[i][1];
	  if(inr(xx,yy))
	    add(xx,yy,z,count,que);
	}
    }
}
bool rh(int i,int j)
{
  return cg[i][j];
  // if(queen)
  //   {
  //     FOR(k,0,8)
  // 	for(int x=i+dirq[k][0],y=j+dirq[k][1];inr(x,y) && 
  // 	      q[x][y]!='#';
  // 	    x+=dirq[k][0],y+=dirq[k][1])
  // 	  if(z[x][y])
  // 	    {
  // 	      return true;
  // 	    }
  // 	  else if(q[x][y]!='.' && q[x][y]!='@')
  // 	    {
  // 	      return false;
  // 	    }
  //   }
  // else
  //   FOR(k,0,8)
  //     {
  // 	int xx=i+dirk[k][0],yy=j+dirk[k][1];
  // 	if(inr(xx,yy) && z[xx][yy])
  // 	  {
  // 	    return true;
  // 	  }
  //     }
  // return false;
}
int att(int z[N][M],int queen,int mi,int c[N][M])
{
  int r(0);
  int aadd(0);
  FOR(i,0,n)
    FOR(j,0,m)
    if(q[i][j]!='.' && q[i][j]!='@' && q[i][j]!='#' && z[i][j]==0 && r<score[q[i][j]] && mi<score[q[i][j]])
      if(rh(i,j))
	{
	  if(cnt[i][j]==0)
	    assert(0);
	  r=score[q[i][j]];
	}
  return r;
}
int z[N][M];
int ccnt[N][M];
int an(int x,int y,int queen)
{
  if(cnt[x][y])
    return 0;
  int ans(0);
  queue<ppi> que;
  memset(z,0,sizeof(z));
  memcpy(ccnt,cnt,sizeof(cnt));
  memset(cg,0,sizeof(cg));
  cg[x][y]=true;
  if(ccnt[x][y]==0)
    {
      z[x][y]=1,que.push(ppi(x,y));
      fill(x,y,z,ccnt,que,queen);
    }
  //cout<<que.front().first<<' '<<que.front().second<<endl;
  for(;!que.empty();)
    {
      ppi v=que.front();
      que.pop();
      int xx=v.first,yy=v.second;
      cg[xx][yy]=true;
       // cout<<"!"<<xx<<' '<<yy<<' '<<q[xx][yy]<<' '<<score[q[xx][yy]]<<endl;
      fill(xx,yy,z,ccnt,que,queen);
      if(q[xx][yy]!='@' && q[xx][yy]!='.')
  	{
	  queue<ppi> qq;
  	  ans+=uncal(xx,yy,ccnt,qq);
	  for(;!qq.empty();qq.pop())
	    {
	      ppi c=qq.front();
	      int xxx=c.first,yyy=c.second;
	      if(z[xxx,yyy]==0 && rh(xxx,yyy))
		que.push(c),z[xxx][yyy]=1;
	    }
  	}
    }
  int ma=att(z,queen,p[6],ccnt);
  if(ma>p[6])
    ans+=ma-p[6];
  return ans;
}
//"P" - pawn, "R" - rook, "K" - knight, "B" - bishop, "Q" - queen, "M" - king, "@" - your starting point 
int main()
{
  scanf("%d %d\n",&n,&m);
  FOR(i,0,7)
    scanf("%d",p+i);
  score['P']=p[0],score['R']=p[1],score['K']=p[2],
    score['B']=p[3],score['Q']=p[4],score['M']=p[5];
  FOR(i,0,n)
    scanf("\n%s",q+i);
  FOR(i,0,n)
    FOR(j,0,m)
    cal(i,j,cnt);
  // FOR(i,0,n)
  //   {
  //     FOR(j,0,m)
  // 	cout<<q[i][j]<<cnt[i][j]<<' ';
  //     cout<<endl<<endl;
  //   }
  if(cnt[rx][ry]==0)
    {
      printf("%d",max(an(rx,ry,0),an(rx,ry,1)));
    }
  else
    {
      int ans(0);
      FOR(i,0,8)
	for(int xx=rx+dirq[i][0],yy=ry+dirq[i][1];
	    inr(xx,yy) && q[xx][yy]!='#';xx+=dirq[i][0],yy+=dirq[i][1])
	  if(cnt[xx][yy]==0)
	    {
	      ans=max(ans,an(xx,yy,1));
	      break;
	    }
	  else if(q[xx][yy]!='.' && q[xx][yy]!='@')
	    {
	      if(q[xx][yy]!='#')
		ans=max(ans,score[q[xx][yy]]-p[6]);
	      break;
	    }
      FOR(i,0,8)
	{
	  int xx=rx+dirk[i][0],yy=ry+dirk[i][1];
	  if(inr(xx,yy) && q[xx][yy]!='#')
	    {
	      if(cnt[xx][yy]==0)
		{
		  ans=max(ans,an(xx,yy,0));
		}
	      else if(q[xx][yy]!='.')
		{
		  ans=max(ans,score[q[xx][yy]]-p[6]);
		}
	    }
	}
      printf("%d",ans);
    }
  return 0;
}
