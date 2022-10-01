class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        vector<string>result;
        map<string,int>indegree;
        map<string, vector<string>>graph;
        for(int i = 0;i<ingredients.size();i++)
        {
            for(auto s: ingredients[i])
            {
                indegree[recipes[i]]++;
                graph[s].push_back(recipes[i]);
            }
        }
        queue<string>q;
        for(auto s: supplies)
        {
            q.push(s);
        }
        while(!q.empty())
        {
            string u = q.front();
            q.pop();
            for(auto s: graph[u])
            {
                indegree[s]--;
                if(indegree[s] == 0)
                {
                    result.push_back(s);
                    q.push(s);
                }
            }
        }
        return result;
    }
};