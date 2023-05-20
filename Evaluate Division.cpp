//https://www.youtube.com/watch?v=C6cm6IvqmyA
//https://leetcode.com/problems/evaluate-division/description/

class Solution {
public:

    void dfs(unordered_map<string,vector<pair<string,double>>>&adj,string src, string dst,unordered_set<string>&visited, double &ans, double product){
        //if already visited
        if(visited.find(src)!=visited.end()){
            return;
        }
        //otherwise mark that src visited
        visited.insert(src);

        if(src==dst){
            ans=product;
            return;
        }

        for(auto &p: adj[src]){
            string new_node = p.first;
            double value = p.second;

            dfs(adj,new_node,dst,visited,ans,value*product);
        }
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        //making an adjacency list
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<n;i++){
            string v = equations[i][0];
            string u = equations[i][1];
            double val = values[i];

            adj[v].push_back({u,val});
            adj[u].push_back({v,1.0/val});
        }

        vector<double>result;

        for(auto &q:queries){
            string src = q[0];
            string dst = q[1];

            double ans = -1.0;
            double product = 1.0;

            //declaring a set for visited string
            if(adj.find(src)!=adj.end()){

                unordered_set<string>visited;
                dfs(adj,src,dst,visited,ans,product);

            }

            result.push_back(ans);

        }

        return result;

    }
};
