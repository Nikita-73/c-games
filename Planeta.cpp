#include "Planeta.h"
#include <string>
#pragma warning( disable : 4996 )

Planeta::Planeta()
{
	name = new char[20];
}
Planeta::Planeta(char* name1, double radnum1, double sredred1, double gravite1)
{
	name = new char[20];
	strcpy(name, name1);
	radnum = radnum1;
	sredred = sredred1;
	gravite = gravite1;
}

Planeta::~Planeta()
{
	delete[] name;
}

void Planeta::setName(char* name1)
{
	
	strcpy(name, name1);
}

void Planeta::setRadnum(double radnum1)
{
	radnum = radnum1;
}

void Planeta::setSredred(double sredred1)
{
	sredred = sredred1;
}

void Planeta::setGravite(double gravite1)
{
	gravite = gravite1;
}

char* Planeta::getName()
{
	return name;
}

double Planeta::getRadnum()
{
	return radnum;
}

double Planeta::getSredred()
{
	return sredred;
}

double Planeta::getGravite()
{
	return gravite;
}

