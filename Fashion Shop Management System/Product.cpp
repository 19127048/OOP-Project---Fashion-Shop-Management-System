#include "Product.h"

int Product::_quantity_out_of_stock = 0;

Product::Product(){}

Product::Product(string product_name, string product_id, string firm_name, string product_type, string product_color, string product_size, 
	double product_cost, double product_price, double discount, TimeOfProduct stock_in_time, TimeOfProduct stock_out_time, TimeOfProduct stock_cover_time) {

	_product_name = product_name;
	_product_id = product_id;
	_firm_name = firm_name;
	_product_type = product_type;
	_product_color = product_color;
	_product_size = product_size;
	_product_cost = product_cost;
	_product_price = product_price;
	_discount = discount;
	_stock_in_time = stock_in_time;
	_stock_out_time = stock_out_time;
	_stock_cover_time = stock_cover_time;

}

void Product::addProductInFile(Product) {

}

void Product::deleteProductInFile(Product) {

}

void Product::modifyProductInFile(string, string) {

}

void Product::parse(string) {

}

void Product::showProductInfo() {

}

void Product::sort(vector<Product>& products, string sort_by) {

	if (sort_by == "_product_name") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductName() > products[j].getProductName())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_id") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductId() > products[j].getProductId())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_firm_name") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getFirmName() > products[j].getFirmName())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_type") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductType() > products[j].getProductType())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_color") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductColor() > products[j].getProductColor())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_size") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductSize() > products[j].getProductSize())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_cost") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductCost() > products[j].getProductCost())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_product_price") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getProductPrice() > products[j].getProductPrice())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_discount") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getDiscount() > products[j].getDiscount())
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_stock_in_time") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getStockInTime().date > products[j].getStockInTime().date)
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_stock_out_time") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getStockOutTime().date > products[j].getStockOutTime().date)
					swap(products[i], products[j]);
		return;
	}

	if (sort_by == "_stock_cover_time") {
		for (int i = 0; i < products.size(); i++)
			for (int j = i + 1; j < products.size() - 1; j++)
				if (products[i].getStockCoverTime().date > products[j].getStockCoverTime().date)
					swap(products[i], products[j]);
		return;
	}
}

Product Product::search_by_ProductId(vector<Product>& products, string search_by) {

	for (int i = 0; i < products.size(); i++)
		if (products[i].getProductId() == search_by)
			return products[i];

}