#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Knapsack
{
private:
    vector<pair<int, int>> items;
    int V;
    vector<pair<int, int>> o;
    int resCapacity;

public:
    Knapsack(int volume) { V = volume; }

    Knapsack(vector<pair<int, int>> newItems, int volume)
    {
        this->items = newItems; // set items
        this->V = volume;
        this->resCapacity = 0;
    }
    int getVolume() const { return V; }
    vector<pair<int, int>> getOptimal() { return this->o; }
    void setVolume(int volume) { V = volume; }
    // void addItem(int newV) { v.push_back(newV); }
    // void addPrice(int newP) { p.push_back(newP); }
    void sortItems()
    {
        sort(items.begin(), items.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            double r1 = (double)a.second / a.first;
            double r2 = (double)b.second / b.first;
            return r1 > r2; });
    }
    int findGreedy()
    {
        // sort items asc
        this->sortItems();
        // look for optimal solution
        for (pair<int, int> item : this->items)
        {
            if (item.first <= this->V)
            {
                o.push_back(item);
                this->resCapacity += item.first;
                this->V -= item.first;
            }
            else
            {
                // take fraction
            }
        }
        return resCapacity;
    }
};

int main()
{
    std::cout << "Fractional 0/1 Knapsack" << std::endl;

    vector<pair<int, int>> i = {{8, 8}, {5, 6}, {5, 6}};

    Knapsack t = Knapsack(i, 10);
    cout << "Total Volume: " << t.getVolume() << endl;
    int o = t.findGreedy();

    cout << "Max Capacity: " << o << endl;
    for (pair<int, int> o : t.getOptimal())
    {
        cout << o.first << "-" << o.second << endl;
    }
    return 0;
}