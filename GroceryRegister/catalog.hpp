#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Product {
public:

	Product() {
	}
	Product(const std::string& code,
		const std::string& name,
		double price) {
		this->code = code;
		this->name = name;
		if (price <= 0) {
			throw std::invalid_argument("Price must be positive.");
		}
		this->price = price;
	}

	~Product() {
	}

	const std::string& getCode() const {
		return code;
	}

	const std::string& getName() const {
		return name;
	}

	double getPrice() const {
		return price;
	}

private:
	std::string code, name;
	double price;
};

class Catalog {
public:

	Catalog(int maxProducts) {
		if (maxProducts <= 0) {
			throw std::invalid_argument("Number of products must be positive.");
		}
		size = maxProducts;
		CatalogList = new Product[size];
		NumOfProduct = 0;
	}

	~Catalog() {
		delete[] CatalogList;
		CatalogList = NULL;
	}

	int getMaxProducts() const {
		return size;
	}

	int getNumProducts() const {
		return NumOfProduct;
	}

	bool isFull() const {
		if (size == NumOfProduct) {
			return true;
		}
		else {
			return false;
		}
	}

	void addProduct(const std::string& code,
		const std::string& name,
		double price) {
		for (int i = 0; i < NumOfProduct; i++)
		{
			if (CatalogList[i].getCode() == code) {
				throw std::invalid_argument("Duplicate code");
			}
		}
		if (price <= 0) {
			throw std::invalid_argument("Price must be positive.");
		}
		if (isFull()) {
			throw std::overflow_error("Catalog list is full_2.");
		}
		Product temp(code, name, price);
		CatalogList[NumOfProduct] = temp;
		NumOfProduct++;
	}

	const Product& findCode(const std::string& code) const {
		for (int i = 0; i < NumOfProduct; i++) {
			if (CatalogList[i].getCode() == code) {
				return CatalogList[i];
			}
		}
		throw std::exception("Not there");
	}
private:
	Product * CatalogList;
	int size;
	int NumOfProduct;
};
