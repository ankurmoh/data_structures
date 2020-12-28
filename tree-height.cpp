#include<bits/stdc++.h>
using namespace std;

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;


  unordered_map<int, vector<int>>graph;
  int root,i,sz,level=0,fron,j,sz1,neigh;
  vector<int>visited(n,0);

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {

    int parent_index;
    std::cin >> parent_index;

    if(parent_index == -1)
      root = child_index;

    else if (parent_index >= 0)
    {
      graph[parent_index].push_back(child_index);
      //graph[child_index].push_back(parent_index);
      nodes[child_index].setParent(&nodes[parent_index]);
    }
    nodes[child_index].key = child_index;
  }

  queue<int>q;
  q.push(root);
  visited[root]=1;
  while(!q.empty())
  {
    sz = q.size();
    for(i=0;i<sz;i++)
    {
      fron = q.front();
      q.pop();
      //cout<<fron<<endl;
      sz1 = graph[fron].size();
      for(j=0;j<sz1;j++)
      {
        neigh = graph[fron][j];
        if(visited[neigh]==0)
        {
          visited[neigh]=1;
          q.push(neigh);
        }
      }
    }
    level++;
  }

  // Replace this code with a faster implementation
  //int maxHeight = 0;
  // for (int leaf_index = 0; leaf_index < n; leaf_index++) {
  //   int height = 0;
  //   for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
  //     height++;
  //   maxHeight = std::max(maxHeight, height);

  cout << level << endl;
  return 0;
}

int main (int argc, char **argv)
{
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
  return main_with_large_stack_space();
}
