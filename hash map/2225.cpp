/********************************************************
// 2225. Find Players With Zero or One Losses

You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:
    answer[0] is a list of all players that have not lost any matches.
    answer[1] is a list of all players that have lost exactly one match.

The values in the two lists should be returned in increasing order.

Note:
    You should only consider the players that have played at least one match.
    The testcases will be generated such that no two matches will have the same outcome.

TAG: Array, Hash Table, Sorting, Counting
*********************************************************/

// BRUTE - using 2 hash tables and a set
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win, loss;
        set<int> players;

        for(vector<int> match: matches) {
            // keep track of players
            players.insert(match[0]);
            players.insert(match[1]);
            // track wins and losses
            win[match[0]]++;
            loss[match[1]]++;
        }

        vector<vector<int>> ans(2, vector<int>());
        // from the total set of players, check players who never lost a match (no record in 'loss')
        for(int p: players) {
            if(loss.find(p) == loss.end()) ans[0].push_back(p);
        }
        // from 'loss', check count of matches lost by each player
        map<int, int>::iterator it;
        for(it=loss.begin(); it!=loss.end(); it++) {
            if(it->second == 1) ans[1].push_back(it->first);
        }
        
        return ans;
    }
};

// OPTIMIZED - one hash table
/*
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> hash;
        for(vector<int> match: matches) {
            hash[match[0]] += 0;    // just to add a record
            hash[match[1]]++;       // keep track of losses
        }

        vector<vector<int>> ans(2, vector<int>());
        map<int, int>::iterator it;
        for(it=hash.begin(); it!=hash.end(); it++) {
            if(it->second == 0) ans[0].push_back(it->first);    // no losses
            if(it->second == 1) ans[1].push_back(it->first);    // exactly one loss
        }
        return ans;
    }
};
*/