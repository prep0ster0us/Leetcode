/********************************************************
// 1496. Path Crossing

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

*********************************************************/

class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.length();
        pair<int,int> lastVisited(0,0);
        set<pair<int,int>> visited;
        visited.insert(lastVisited);
        
        for(int i=0; i<n; i++) {
            pair<int,int> temp;
            if(path[i] == 'N') {
                temp = make_pair(lastVisited.first, lastVisited.second+1);
            } else if(path[i] == 'S') {
                temp = make_pair(lastVisited.first, lastVisited.second-1);
            } else if(path[i] == 'W') {
                temp = make_pair(lastVisited.first-1, lastVisited.second);
            } else if(path[i] == 'E') {
                temp = make_pair(lastVisited.first+1, lastVisited.second);
            }
            // debug prints
            cout << temp.first << ":" << temp.second << endl;
            cout << "set currently: ";
            set<pair<int,int>>::iterator it;
            for(it = visited.begin(); it != visited.end(); it++) {
                cout << it->first << ":" << it->second << "  ";
            }
            cout << endl;
            // debug prints
            
            // check if in path
            if(visited.contains(temp)) {
                return true;
            } else {
                // mark as visited in path
                visited.insert(temp);
                lastVisited = temp;
            }
        }
        return false;
    }
};