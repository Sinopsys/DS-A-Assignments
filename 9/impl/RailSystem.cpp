//
// Created by kirill on 14.03.17.
//

#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "RailSystem.h"
#include <map>
#include <list>
#include <vector>


const int INFTY = INT_MAX;

void RailSystem::reset(void)
{
    // reset the data objects of the
    // City objects' contained in cities
    //
    for (std::map<string, City *>::iterator it = cities.begin(); it != cities.end(); ++it)
    {
        it->second->visited = false;
        it->second->total_distance = INFTY;
        it->second->total_fee = INFTY;
        it->second->from_city = "";
    }
}

RailSystem::RailSystem(string const &filename)
{

    load_services(filename);
}

void RailSystem::load_services(string const &filename)
{

    ifstream inf(filename.c_str());
    string from, to;
    int fee, distance;

    while (inf.good())
    {

        // Read in the from city, to city, the fee, and distance.
        inf >> from >> to >> fee >> distance;

        if (inf.good())
        {

            // Add entries in the cities container and
            // and services in the rail system for the new
            // cities we read in.
            //
            std::map<string, City *>::iterator it = cities.find(from);
            if (it == cities.end())
                cities[from] = new City(from);

            // reset iterator
            //
            it = cities.begin();

            // find 'to' town
            //
            it = cities.find(to);

            if (it == cities.end())
                cities[to] = new City(to);

            // find services that connect 'from' and 'to' city
            //
            if (outgoing_services.find(from) == outgoing_services.end())
                outgoing_services[from] = std::list<Service *>();
            outgoing_services[from].push_back(new Service(to, fee, distance));
        }
    }

    inf.close();
}

RailSystem::~RailSystem(void)
{

    // release all the City* and Service*
    // from cities and outgoing_services
    //
    for (std::map<string, City *>::iterator it = cities.begin(); it != cities.end(); ++it)
        delete it->second;

    for (std::map<string, std::list<Service *> >::iterator it = outgoing_services.begin();
         it != outgoing_services.end();
         ++it)
        for (std::list<Service *>::iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1)
        {
            Service *tmp = *it1;
            delete tmp;
        }

}

void RailSystem::output_cheapest_route(const string &from,
                                       const string &to, ostream &out)
{

    reset();
    pair<int, int> totals = calc_route(from, to);

    if (totals.first == INFTY)
    {
        out << "There is no route from " << from << " to " << to << "\n";
    } else
    {
        out << "The cheapest route from " << from << " to " << to << "\n";
        out << "costs " << totals.first << " euros and spans " << totals.second
            << " kilometers\n";
        cout << recover_route(to) << "\n\n";
    }
}

bool RailSystem::is_valid_city(const string &name)
{

    return cities.count(name) == 1;
}

pair<int, int> RailSystem::calc_route(string from, string to)
{
    // You can use another container
    priority_queue<City *, vector<City *>, Cheapest> candidates;

    // Dijkstra's shortest path algorithm to
    // find the cheapest route between the cities
    //
    cities[from]->total_distance = 0;
    cities[from]->total_fee = 0;

    // push all cities to queue
    //
    for (std::map<string, City *>::iterator it = cities.begin(); it != cities.end(); ++it)
        candidates.push(it->second);

    while (candidates.size() > 0)
    {
        // tak closest city
        //
        City *closest = candidates.top();

        if (closest->total_distance == INT_MAX)
            break;

        // mark city as visited
        //
        cities[closest->name]->visited = true;

        // then remove it
        //
        candidates.pop();

        // found closest
        //
        if (closest->name == to)
            break;

        // Dijkstra algorithm
        //
        for (std::list<Service *>::iterator it = outgoing_services[closest->name].begin();
             it != outgoing_services[closest->name].end();
             ++it)
        {
            City *next = cities[(*it)->destination];
            int fee = closest->total_fee + (*it)->fee;
            if (fee < next->total_fee)
            {
                next->total_distance = closest->total_distance + (*it)->distance;
                next->total_fee = fee;
                next->from_city = closest->name;
            }
        }
        std::make_heap(const_cast<City **>(&candidates.top()),
                       const_cast<City **>(&candidates.top()) + candidates.size(),
                       Cheapest());
    }

    // Return the total fee and total distance.
    // Return (INT_MAX, INT_MAX) if not path is found.
    if (cities[to]->visited)
    {
        return std::pair<int, int>(cities[to]->total_fee, cities[to]->total_distance);
    } else
    {
        return std::pair<int, int>(INT_MAX, INT_MAX);
    }

}

string RailSystem::recover_route(const string &city)
{

    // walk backwards through the cities
    // container to recover the route we found
    //
    City *cty = cities[city];
    string res = cty->name;
    while (cty->from_city != "")
    {
        cty = cities[cty->from_city];
        res = cty->name + " -> " + res;
    }
    return res;
}


Route RailSystem::getCheapestRoute(const string &from, const string &to)
{
    assert(is_valid_city(from));
    assert(is_valid_city(to));
    reset();
    pair<int, int> p = calc_route(from, to);
    return Route(from, to, p.first, p.second);
}


// EOF
