#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N (100000)
int p[N+1][3];
int q[(N+6)*2+1][3],qoi;
int s[N+6],x[N+6];
int S,T;
int pos[3],n;
int pp[3];
int giv[N+1];
static const char op[]={'P','O','S','!'};
void set(int a,int b)
{
    giv[a]=b;
}
void lk(int a,int b,int v)
{
    q[qoi][0]=b,q[qoi][1]=s[a],q[qoi][2]=v,s[a]=qoi++;
    q[qoi][0]=a,q[qoi][1]=s[b],q[qoi][2]=0,s[b]=qoi++;
}
int que[N];
int d[N+6];
bool bfs()
{
    int f,l;
    f=0,l=1;
    que[f]=S;
    d[S]=1;
    memset(d,0,sizeof(d));
    memcpy(x,s,sizeof(x));
    for(;f<l;++f)
    {
        int i=que[f];
        for(int j=x[i];j;j=q[j][1])
            if(q[j][2]>0 && !d[q[j][0]])
                d[q[j][0]]=d[i]+1,que[l++]=q[j][0];
    }
    return (d[T]>0);
}
int dfs(int v,int f)
{
    if(v==T)
        return f;
    int r=f,i;
    for(i=x[v];i;i=q[i][1])
        if(q[i][2]>0 && d[v]+1==d[q[i][0]])
        {
            int tmp=dfs(q[i][0],min(q[i][2],f));
            q[i][2]-=tmp;
            q[(i&1)?(i+1):(i-1)][2]+=tmp;
            f-=tmp;
            if(f==0) break;
        }
    x[v]=i;
    return r-f;
}
int din(int v)
{
    int cc=0;
    for(;v>0&&bfs();)
        for(int tmp;v>0&&(tmp=dfs(S,v));)
            v-=tmp;
    return v;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",pos,pos+1,pos+2,&n);
    S=n+1,T=S+1;
    for(int i=0;i<3;++i)
    {
        pp[i]=T+1+i;
        lk(S,pp[i],pos[i]>0?pos[i]:0);
    }
    for(int i=1;i<=n;++i)
    {
        char t;
        bool w=1;
        scanf("%c",&t);
        for(int j=0;j<3;++j)
        {
            scanf("%c",&t);
            p[i][j]=(t=='B'?2:1);
            if(p[i][j]==2)
                w=0,lk(pp[j],i,2);
        }
        if(w)
        {
            for(int j=0;j<3;++j)
                lk(pp[j],i,1);
            lk(i,T,1);
        }
        else lk(i,T,2);
    }
    int all=0;
    for(int i=0;i<3;++i)
        all+=pos[i];
    din(all);
    for(int i=1;i<=n;++i)
        giv[i]=3;
    for(int i=0;i<3;++i)
        for(int j=s[pp[i]];j;j=q[j][1])
            if(q[j+1][2])
                set(q[j][0],i);
    for(int i=1;i<=n;++i)
        printf("%c",op[giv[i]]);
    if(all>0)
        printf("no solution");
    else
    {
        for(int i=1;i<=n;++i)
            printf("%c",op[giv[i]]);
    }
    return 0;
}
