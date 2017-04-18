// Kupriyanov Kirill BSE151
//

#include "parts.h"
#include <iostream>

void Part::describe() const
{
    std::cout << "Part " << this->name << "subparts are: \n";
    if (subparts.size() == 0)
        std::cout << "\tIt has no subparts" << std::endl;
    for (const auto &sub_p : this->subparts)
        std::cout << "\t" << sub_p.second << " " << (sub_p.first)->name << "\n";
}

int Part::countHowMany(const Part* p) const
{
    if (p == this)
        return 1;
    int sum = 0;
    for (const auto& part : this->subparts)
        sum += (part.first)->countHowMany(p) * part.second;
    return sum;
}

Part* NameContainer::lookup(const std::string& name)
{
    auto it = _nameMap.find(name);
    // if name not found
    //
    if (it == _nameMap.end())
    { 
        _nameMap[name] = new Part(name);
        return _nameMap[name];
    }
    else
        return it->second;
}

void NameContainer::addPart(const std::string& part, int quantity, const std::string& subpart)
{
    Part* p = lookup(part);
    Part* child = lookup(subpart);
    (p->subparts)[child] = quantity;
}

NameContainer::~NameContainer()
{
    for (auto pair : _nameMap)
        delete pair.second;
}


// EOF

