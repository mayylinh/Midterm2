#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

class Human
{
	private:
		std::string name;
		int age;
		char sex;

		Human() 
		{ 
			name = "Jane Doe";
			age = 0;
			sex = 'F';
		};

	protected:
		Human(const std::string & nombre, const int & years, const char & gender)
			: name(nombre), age(years), sex(gender) {};
		virtual ~Human() {};

	public:
		void setName(std::string nombre) { name = nombre;  }
		void setAge(int years) { age = years; }
		void setSex(char gender) { sex = gender; }

		std::string getName() { return name; }
		int getAge() { return age; }
		char getSex() { return sex; }
};

class Child : public Human
{
	private:
		std::string momName, dadName;
		int allowance;

		Child() : Human("Janine", 0, 'F'), 
				  momName("Jane"), dadName("John"), allowance(0) {};

		friend class Parent;

	public:
		Child(std::string nombre, int years, char gender)
			: Human(nombre, years, gender), momName(), dadName(), allowance(0) {};

		int getAllowance() const 
		{
			std::cout << "Allowance: " << allowance; 
			return allowance;
		}
		void printParents() 
		{
			std::cout << "Mom: " << momName << std::endl;
			std::cout << "Dad: " << dadName << std::endl;
		}
};

class Parent : public Human
{
	private:
		std::vector<std::string> children;

		Parent() : Human("Jane Doe", 0, 'F') {};

	public:
		Parent(std::string nombre, int years, char gender)
			: Human(nombre, years, gender) {};

		void printChild()
		{
			for (auto i = children.begin(); i != children.end(); ++i)
				std::cout << *i << " ";
		}
		void setChild(Child kid)
		{
			children.push_back(kid.getName());
		}
		void setChildAllowance(int money, Child kid)
		{
			for (int i = 0; i < children.size(); i++)
				if (children.at(i).compare(kid.getName())
					kid.allowance(money);
		}
};