#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Knapsack
{
private:
    vector<pair<double, double>> items;
    double V;
    vector<pair<double, double>> o;
    double resValue;
    double resCapacity;

public:
    Knapsack(double volume) { V = volume; }
    Knapsack(vector<pair<double, double>> newItems, double volume)
    {
        this->items = newItems; // set items
        this->V = volume;
        this->resValue = 0;
        this->resCapacity = 0;
    }
    double getVolume() const { return V; }
    double getCapacity() const { return this->resCapacity; }
    double getValue() const { return this->resValue; }

    vector<pair<double, double>> getOptimal() { return this->o; }
    void setVolume(double volume) { V = volume; }
    void sortItems()
    {
        sort(items.begin(), items.end(), [](const pair<double, double> &a, const pair<double, double> &b)
             {
            double r1 = (double)a.second / a.first;
            double r2 = (double)b.second / b.first;
            return r1 > r2; });
    }
    void printItems()
    {
        for (pair<double, double> o : this->items)
        {
            cout << o.first << "-" << o.second << endl;
        }
    }
    double findGreedy()
    {
        // sort items asc
        this->sortItems();
        // look for optimal solution
        for (pair<double, double> item : this->items)
        {
            if (item.first <= this->V)
            {
                o.push_back(item);
                this->resValue += item.second;
                this->resCapacity += item.first;
                this->V -= item.first;
            }
            else
            {
                // take fraction
                this->resValue += item.second * this->V / item.first;
                this->resCapacity += this->V;
                o.push_back({this->V, item.second * this->V / item.first});
                this->V = 0;
                break;
            }
        }
        return resValue;
    }
};

int main()
{
    cout << "Fractional 0/1 Knapsack" << endl;

    // test items
    vector<pair<double, double>> i = {{8, 8}, {5, 6}, {5, 6}};
    vector<pair<double, double>> j = {{4, 4}, {6, 9}, {1, 2}, {2, 5}};
    vector<pair<double, double>> k = {{6, 12}, {4, 8}, {5, 10}};

    Knapsack t = Knapsack(k, 7);                       // create new knapsack with items and volume
    cout << "Total Volume: " << t.getVolume() << endl; // print total volume
    cout << "Items: " << endl;
    t.printItems();                                     // print all items
    double o = t.findGreedy();                          // find best optimal solution
    cout << "Max. Volume: " << t.getCapacity() << endl; // print optimal volume
    cout << "Max. Value: " << o << endl;                // print optimal value
    for (pair<double, double> o : t.getOptimal())       // print optimal items
    {
        cout << o.first << "-" << o.second << endl;
    }
    return 0;
}