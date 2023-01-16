class Solution {
public:
    vector<bool> visited;
    vector<int> ans;
   
    vector<int> dft(vector<vector<int>> &graph, int curr, vector<int> l, string &labels){
        
        visited[curr] = true;
        
        if(graph[curr].size() == 1 and curr != 0){
            l[labels[curr]-'a']++;
            ans[curr] = l[labels[curr]-'a'];
            return l;
        }
        int count = 0;
        vector<int> ret;
        for(auto nbr : graph[curr]){
            if(!visited[nbr]){
                ret = dft(graph, nbr, l, labels);
                count += ret[labels[curr]-'a'];
            }
                
        }
        ret[labels[curr]-'a']++;
        ans[curr] = count+1;
        
        return ret;
        
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        visited.resize(n, false);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        
        ans.resize(n, 0);
        
        vector<int> l(26,0);
//         for(auto node : graph)
//             cout<<node.size();
        
        dft(graph, 0, l, labels);
        
        return ans;
        
        
    }
};
