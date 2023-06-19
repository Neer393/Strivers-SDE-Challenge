#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode * solve(graphNode * node,unordered_map<graphNode *,graphNode *> &mp){
        if(!node)   return NULL;
        graphNode * new_node = new graphNode(node->data);
        mp[node]=new_node;
        for(auto neighbour: node->neighbours){
            if(mp.find(neighbour)!=mp.end()){
                new_node->neighbours.push_back(mp[neighbour]);
            }
            else{
                new_node->neighbours.push_back(solve(neighbour,mp));
            }
        }
        return new_node;
    }

graphNode *cloneGraph(graphNode *node)
{
    unordered_map<graphNode *,graphNode *> mp;
    return solve(node,mp);
}
