#ifndef _MEMBERSHIP_LEVEL_
#define _MEMBERSHIP_LEVEL_


#include <iostream>
#include <string>

using namespace std;

class MembershipLevel
{
private:

	string _level;
	static int _cumulative_points;

public:

	void setLevel(string);
	string getLevel();
	void setCumulativePoints(int);
	int getCummulativePoints();
	int increaseCumulativePoints();
	double getDiscount(string _level);
	void updateLevel();

	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;

	friend class Account;
};


#endif // !_MEMBERSHIP_LEVEL_