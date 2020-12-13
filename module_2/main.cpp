//
// Created by Andrew Kireev on 04.12.2020.
//

#include <set>
#include <iostream>
#include <tuple>



struct Person {
	std::string FirstName;
	std::string SecondName;
	int ChildCount;
};

struct DefaultComparator {
public:
	bool operator()(const Person& lhs, const Person& rhs) const {
		return std::tie(lhs.FirstName, lhs.SecondName, lhs.ChildCount)
		< std::tie(rhs.FirstName, rhs.SecondName, rhs.ChildCount);
	}
};

int main() {
	std::set<Person, DefaultComparator> persons;

	persons.insert({"fdfsfds", "fdsfsdfs", 432423});
	persons.insert({"fdsfsaewr", "fdsfsdfs", 432423});
	return 0;
}

