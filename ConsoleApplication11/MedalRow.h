#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
class MedalRow
{
	char country[4];
	int medals[3];

public:
	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };
	MedalRow(const char* countryP, const int* medalsP) 
	{
		strcpy_s(country, 4, countryP ? countryP : "NON");
		for (int i{ 0 }; i < 3; ++i) 
		{
			medals[i] = medalsP ? medalsP[i] : 0;
		}
	}
	MedalRow() : MedalRow(nullptr,nullptr) {}
	MedalRow& setCountry(const char* countryP) 
	{
		if (countryP) 
		{
			strcpy_s(country, 4, countryP);

		}
		return *this;
	}
	
	const char* getCountry()const { return country; }
	const int* getMedals()const { return medals; }
	int& operator[](int idx) 
	{
		assert((idx >= 0 and idx < 3) and "Index out" "of range!");
		return medals[idx];
	}
	int operator[](int idx) const 
	{
		assert((idx >= 0 and idx < 3) and "Index out" "of range!");
		return medals[idx];
	}
	void print()const 
	{
		std::cout << "[" << country << "]-(";
		for (int i{ 0 }; i < 3; ++i) 
		{
			std::cout << medals[i];
			if (i < 2) { std::cout << "\t"; }
		}
		std::cout << ")\n";
	}
	friend std::ostream& operator<<(std::ostream out, MedalRow& medalRow)
	{
		out << '[' << medalRow.country << "]-( ";
		for (int i{ 0 }; i < 3; ++i)
		{
			out << medalRow.medals[i];
			if (i < 2) { out << '\t'; }
		}
		out << " )\n";
		return out;
    }
	
};

