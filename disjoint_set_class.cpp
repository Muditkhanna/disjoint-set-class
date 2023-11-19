class disjoint_set
{
	vector<int>rank;
	vector<int>size;
	vector<int>parent;
private:
  
public:
	 disjoint_set(int n)
	 {
	   rank.resize(n+1,0);
	   size.resize(n+1,1);
	   parent.resize(n+1);
       for(int i=0;i<=n;i++)
       {
       	 parent[i]=i;
       }
	 }
	
	void union_by_rank(int u,int v)
	{
        int parent_u=ancestor(u);
        int parent_v=ancestor(v);

        if(parent_u==parent_v)return;

        if(rank[parent_u]>rank[parent_v])
        {
           parent[parent_v]=parent_u;
        }
        else if(rank[parent_u]<rank[parent_v])
        {
           parent[parent_u]=parent_v;
        }
        else
        {
        	parent[parent_u]=parent_v;
        	rank[parent_v]++;
        }
	}
    
    void union_by_size(int x,int y)
    {
    	int parent_x=ancestor(x);
    	int parent_y=ancestor(y);
    	if(parent_x==parent_y)return;
         if(size[parent_x]>size[parent_y])
         {
         	parent[parent_y]=parent_x;
            size[parent_x]+=size[parent_y];
         }
         else 
         {
         	parent[parent_x]=parent_y;
         	size[parent_y]+=size[parent_x];
         }
    }
	bool same_component(int x,int y)
	{
		return ancestor(x)==ancestor(y);
	}

	int ancestor(int node)
	{
       if(parent[node]==node)return node;

       return parent[node]=ancestor(parent[node]);
	}
	
};
