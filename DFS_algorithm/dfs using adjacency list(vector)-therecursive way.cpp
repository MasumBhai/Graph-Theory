//dfs in iterative way
//here is no use for adjcency matrix,i just used it to show how the graph looks in adjacent_matrix way
#include<bits/stdc++.h>
#include<stdio.h>
#include<fstream>
#define MAX_VER 50
using namespace std;

int N,E,x,y,w;
bool dir;
int adj_matrix[MAX_VER][MAX_VER];   //this is also 2d vector
vector<vector<int>> adj_list;       //this is a 2d vector
vector<int> visited(MAX_VER,false); //this is my visited array

void Graph_initialization()
{
    cout<<"input the total number of vertices:"<<endl;
    cin>>N;
    cout<<"input the total edges:"<<endl;
    cin>>E;
    adj_list.resize(N+1);           //this is to give space for the vertices
    cout<<"Is the graph dircted? 1 or 0 :"<<endl;
    cin>>dir;
    cout<<"input the edges:"<<endl;
    //below is for adjacency_matrix
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            adj_matrix[i][j]=0;
        }
    }
    while(E--)
    {
        cin>>x>>y;
        if(dir == false)
        {
            //below is for undirected graph
            adj_matrix[x][y]=1;
            adj_matrix[y][x]=1;
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        }
        else
        {
            //below is for directed graph
            adj_matrix[x][y]=1;
            adj_list[x].push_back(y);
        }
    }
}

void print_adjacency_list()
{
    cout<<"adjacency list printed :"<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<i<<"->";
        for(int j=0; j<adj_list[i].size(); j++)
        {
            cout<<adj_list[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print_adjeceny_matrix()
{
    cout<<"adjacency matrix printed :"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<adj_matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void Recursive_DFS(int s)
{
    int curr = s;
    cout<<s<<" ";
    visited[s]=true;
    for(int i=0; i< adj_list[curr].size(); i++)
    {
        if(visited[adj_list[curr][i]]==false)
        {
            visited[adj_list[curr][i]]=true;
            Recursive_DFS(adj_list[curr][i]);
        }
    }
}

int main()
{
    Graph_initialization();
    print_adjeceny_matrix();
    print_adjacency_list();
    cout<<"please input the source vertex: ";
    int source;
    cin>>source;
    cout<<"Depth Order Search: ";
    Recursive_DFS(source);
//    int component=0;
//    for(int i=0; i<N; i++)
//    {
//        if(!visited[i])
//        {
//            Recursive_DFS(i);
//            component++;
//        }
//    }
//    cout<<endl<<"Connected components: "<<component<<endl;
//uncomment these & comment out 100-104 lines to get connected components
    return 0;
}
/*
13
14
0
0 1
0 9
1 8
8 9
2 3
3 4
3 7
3 5
7 8
5 6
6 7
7 10
7 11
10 11
*/
//3 5 6 7 11 10 8 9 0 1 4 2 , this is the output in iterative way , if the source is 3
//3 2 4 7 8 1 0 9 6 5 10 11 , this is the output in recursive way , if the source is 3
