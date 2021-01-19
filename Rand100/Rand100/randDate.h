#pragma once
#include <ctime>
#include <string>


class randDate
{
	int day;
	int month;
	int year;
	std::string g; 
	std::string h;
	
	
public:
	randDate();
	std::string getRandDate();
	char randLat();
	char randRus();
	double randD();
};

