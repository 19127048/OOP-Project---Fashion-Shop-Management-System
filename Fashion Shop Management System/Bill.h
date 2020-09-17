#ifndef _BILL_
#define _BILL_


#include <iostream>
#include <string>
#include <Date.h>
#include <Time.h>


#include "Product.h"
#include "MembershipLevel.h"


class Bill
{
private:

	string _bill_id;
	string _level;
	MembershipLevel _membership;
	Date _curr_date;
	vector<Product> _cart;

public:

	Bill()
	{

	}

	Bill(string id, string level, MembershipLevel membership, Date d, vector<Product> p);

public:

	void sort(vector <Bill> bills, string sort_by);

	Bill search(vector <Bill> bills, string search_by);

	void setBillInfo(vector<string>);

	Bill getBill();

	static string getLastBillID(vector <Bill> bills);

	static string lastBill_ID_InFile();

	string getID();

	Date getDate();

	string toString();

	void showBillInfo();

	static void saveBillToFile(vector <Bill> bills);

	static void openBillFile(vector <Bill>& bills, string path = "Bill.csv");

public:

	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};


#endif // !_BILL_