// parts.h

#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>

//**************** Part ****************
class Part  {
public:
	std::string name;

    std::map<const Part*, int> subparts;
	
	Part(const std::string& n) : name(n) {};
	void describe() const;
	int countHowMany(const Part*) const;
};


//**************** NameContainer ****************
class NameContainer  {
public:        
	NameContainer() {};
    ~NameContainer();

    void addPart(const std::string& part, int quantity, const std::string& subpart);
	Part* lookup(const std::string& name);
private:
	std::map<std::string, Part*> _nameMap;
};

#endif // _PARTS_H_


// EOF

