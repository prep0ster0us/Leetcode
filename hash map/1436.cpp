/********************************************************
// 1436. Destination City

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

*********************************************************/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> hash;
        unordered_set<string> start;
        for(vector<string> path: paths) {
            hash[path[1]]++;
            start.insert(path[0]);
        }
        unordered_map<string, int>::iterator it;
        for(it=hash.begin(); it!=hash.end(); it++) {
            if(it->second == 1 && !start.contains(it->first)) {
                return it->first;
            }
        }
        return "";
    }
};