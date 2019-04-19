#include "stdafx.h"
#include "Midterm2.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char ** argv) 
{
	Parent dad("Homer", 36, 'M');
	Parent mom("Marge", 34, 'F');

	Child girl("Lisa", 12, 'F');
	Child boy("Bart", 10, 'M');
	Child baby("Maggie", 3, 'F');

	dad.setChild(girl);
	dad.setChild(boy);
	dad.setChild(baby);

	std::cout << "Bart's current allowance: " << boy.getAllowance();

	dad.setChildAllowance(5, boy);

	std::cout << "Bart's current allowance set by Homer: " << boy.getAllowance();

	boy.printParents();

	printInfo(mom);
	printInfo(girl);

	return 0;
}

void printInfo(Human person)
{
	std::cout << "Name: " << person.getName() << std::endl;
	std::cout << "Age: " << person.getAge() << std::endl;
	std::cout << "Sex: " << person.getSex() << std::endl;
}