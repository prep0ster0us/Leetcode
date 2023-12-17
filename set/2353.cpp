/********************************************************
// 2353. Design a Food Rating System

Design a food rating system that can do the following:

    Modify the rating of a food item listed in the system.
    Return the highest-rated food item for a type of cuisine in the system.

Implement the FoodRatings class:

    FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.
        foods[i] is the name of the ith food,
        cuisines[i] is the type of cuisine of the ith food, and
        ratings[i] is the initial rating of the ith food.
    void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
    String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

*********************************************************/

class FoodRatings {
private:
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> foodSortMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0; i<n; i++) {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            foodSortMap[cuisines[i]].insert({
                -ratings[i],
                foods[i]
            });
        }
    }
    
    void changeRating(string food, int newRating) {
        set<pair<int,string>>::iterator it;
        it = foodSortMap[foodCuisine[food]].find({
            -foodRating[food], food
        });
        // remove
        foodSortMap[foodCuisine[food]].erase(it);
        foodRating[food] = newRating;

        // add updated
        foodSortMap[foodCuisine[food]].insert({
            -newRating, 
            food
        });
    }
    
    string highestRated(string cuisine) {
        set<pair<int, string>>::iterator max = foodSortMap[cuisine].begin();
        return max->second;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */