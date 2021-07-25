#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 1005;

int find_num,vertex,edge;
vector <int> mygraph[MAX];
queue <int> Queue;
bool check[MAX];



void BFS(int find)
{
    printf("%d ",find);
    Queue.push(find);
    check[find] = true;
    while(!Queue.empty())
    {
        int cur = Queue.front();
        Queue.pop();
        for(int i = 0; i < mygraph[cur].size(); i++)
        {
            int next = mygraph[cur][i];
            if(check[next] == false)
            {
                printf("%d ",next);
                Queue.push(next);
                check[next] = true;
            }
        }
    }
    printf("\n");
}
void DFS(int find)
{
    printf("%d ",find);
    check[find] = true;
    for(int i =0; i < mygraph[find].size(); i++)
    {
        int next = mygraph[find][i];
        if(check[next] == false)
        {
            //printf("%d ",next);
            DFS(next);
        }
    }
}
int main()
{
    scanf("%d %d %d",&vertex,&edge,&find_num);
    for(int i =0; i < edge; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        mygraph[a].push_back(b);
        mygraph[b].push_back(a);
    }
    for(int i=0; i < vertex; i++)
        sort(mygraph[i].begin(),mygraph[i].end());
    DFS(find_num);
    printf("\n");
    memset(check,0,MAX * sizeof(check[0]));
    BFS(find_num);
    return 0;
}
