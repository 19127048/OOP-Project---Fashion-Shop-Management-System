#include "Shop.h"



/// <summary>
/// Load list
/// </summary>

void Shop::openProductList()
{
	Product::setProductsInfo(_products);
}

void Shop::openBillList()
{
	Bill::openBillFile(_bills);
}

void Shop::openAccountList()
{
	Account::openAccountFile(_accounts);
}

void Shop::openStaffList()
{
	Staff::openStaffToRead(_staffs);
}

/// <summary>
///		Save	///
/// </summary>

void Shop::saveProductList()
{

}

void Shop::saveBillList()
{
	Bill::saveBillToFile(_bills);
}

void Shop::saveAccountList()
{
	Account::saveAccountToFile(_accounts);
}

void Shop::saveStaffList()
{
	Staff::saveStaffInfoToFile(_staffs);
}

/// <summary>
///		Sort	///
/// </summary>
/// <param name="sort_by"></param>

void Shop::sortProduct()
{
	Product::sort(_products, "_product_id");
}

void Shop::sortAccount()
{
	Account account;
	account.sort(_accounts, "id");
}

void Shop::sortStaff(string sort_by)
{
}

/// <summary>
///		Show	///
/// </summary>
void Shop::showProductList()
{
	Product::showProductsInfo(_products);
}

void Shop::showStaffList()
{
	for (int i = 0; i< _staffs.size(); i++)
	{
		_staffs[i]->showStaffInfo();
		cout << endl;
	}
}

////////////////////		SWITCH\CASE		////////////////////

void Shop::Start()
{
	bool is_continue = true;
	int choice;


	Menu::showMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			Purchase();
			break;

		case 2:

			ProductManagement();
			break;

		case 3:

			StaffInfoManagement();
			break;

		case 4:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
	}
	
}

/// <summary>
///			Purchase		///
/// </summary>

void Shop::Purchase()
{
	system("cls");


	cout << "Product list\n";
	showProductList();


	vector <Product> products_sold;
	Product product;

	int index;
	string id;
	cout << "Enter product's id: ";
	getline(cin, id);

	int amount;
	cout << "Amount: ";
	cin >> amount;
	cin.ignore();

	vector <Product> cart;

	for (int i = 0; i < amount; i++)
	{
		if (Product::isValidInList(_products, id, index)) {
			product = Product::search_by_ProductId(_products, index);
			Product::buyProduct(_products, products_sold, product);

			cart.push_back(product);
		}
		else
		{
			cout << "the product is out of stock" << endl;
			return;
		}
	}


	long long int new_id = stoll(Bill::getLastBillID(_bills)) + 1;
	Account account;
	account = AccountManagement();
	Bill bill(to_string(new_id), account.getMemberShipLevel(), account.getMemberShip(), Date(), cart);
	_bills.push_back(bill);
	bill.showBillInfo();


	MembershipLevel update(account.getMemberShip().getLevel(), account.getMemberShip().getCummulativePoints() + cart.size());
	update.updateLevel();
	account.setMemberShip(update);
	updateList(_accounts, account);
}

/// <summary>
///			Account Management		////
/// </summary>
/// return Account

Account Shop::AccountManagement()
{
	system("cls");
	bool is_continue = true;


	string id;
	Account new_account;


	int choice;
	Menu::showAccountMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			cout << "Enter your account id: ";
			getline(cin, id);
			try
			{
				return Account::sign_in(_accounts, id);
			}
			catch (const std::exception& error)
			{
				cout << error.what() << endl;
			}
			break;

		case 2:

			new_account = new_account.sign_up(_accounts);
			return new_account;

		case 3:

			is_continue = false;
			continue;
		}
	}


	return new_account;
}

/// <summary>
///			Product management		///
/// </summary>

void Shop::ProductManagement()
{

	system("cls");
	bool is_continue = true;


	Product new_product;
	string id;
	

	int choice;
	Menu::showProductManagementMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			system("cls");
			if (new_product.set() == "cancel")
			{
				break;
			}
			Product::addProductInFile(_products, new_product);
			break;

		case 2:

			system("cls");
			showProductList();
			cout << "Enter product's ID: ";
			getline(cin, id);
			if (id == "cancel")
			{
				cout << "Cancel!!!\n";
				break;
			}
			

			int index;
			while (Product::isValidInList(_products, id, index))
			{
				if (!(Product::isValidInList(_products, id, index)))
				{
					cout << "Not found\n";
				}
				Product::deleteProductInFile(_products, Product::search_by_ProductId(_products, index));
			}
			break;

		case 3:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showProductManagementMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
	}
}

/// <summary>
///			Staff management		///
/// </summary>

void Shop::StaffInfoManagement()
{
	system("cls");
	bool is_continue = true;


	string id;
	Staff* staff = nullptr;


	int choice;
	Menu::showStaffMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			cout << "Enter your Staff ID: ";
			getline(cin, id);


			staff = Staff::search(_staffs, id);
			staff->showStaffInfo();
			cout << endl;

			break;

		case 2:

			SellerInfo();
			break;

		case 3:

			SecurityInfo();
			break;

		case 4:

			is_continue = false;
			continue;

		}

		
		system("pause");
		system("cls");


		Menu::showStaffMenu();
		cout << "Choose: ";
		cin >> choice;
		cin.ignore();
	}
}

void Shop::SellerInfo()
{
	system("cls");
	bool is_continue = true;
	int choice;


	string id;


	Menu::showSellerMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			break;

		case 2:

			cout << "Enter seller id: ";
			
			getline(cin, id);

			
			for (int i = 0; i < _staffs.size(); i++)
			{

			}
			break;

		case 3:

			break;

		case 4:

			break;

		case 5:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showSellerMenu();
		cout << "Choose: ";
		cin >> choice;
	}
}

void Shop::SecurityInfo()
{
	system("cls");
	bool is_continue = true;
	int choice;


	string id;


	Menu::showSecurityMenu();
	cout << "Choose: ";
	cin >> choice;
	cin.ignore();
	while (is_continue)
	{
		switch (choice)
		{
		case 1:

			break;

		case 2:

			break;

		case 3:

			is_continue = false;
			continue;

		}


		system("pause");
		system("cls");


		Menu::showSecurityMenu();
		cout << "Choose: ";
		cin >> choice;
	}
}
