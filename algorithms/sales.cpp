/*
	Solutions to examples, exercises & problems from the book: "C++ Primer, 5th ed."
	copyright @vinaykumar2491 27/09/2017 
*/

#include <iostream>
#include <string>
#include "Sales_data.h"
// #include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
// using std::runtime_error;

int main(){
	Sales_data data1, data2;
	
	// code to read data1 and data2
	double price = 0;		// price per book, used to calculate total revenue
		// reading into data1
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
		// reading into data2
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	
	// code to check whether data1 and data2 have same ISBN
	//		and if so then print the sum of data1 and data2
	
	if(data1.bookNo == data2.bookNo){
		unsigned totalCount = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		
		// print ISBN, total sold, total revenue, average-price-per-book
		std::cout << data1.bookNo << " " << totalCount << " " << totalRevenue << " ";
		if (totalCount != 0){
			std::cout << totalRevenue/totalCount << std::endl;
		}
		else{
			std::cout << "(no sales)" << std::endl;
		}
		return 0;		// indicates SUCCESS
	}
	else{		// data1 & data2 transactions weren't for the same ISBN
		std::cerr << "Data must refer the same ISBN" << std::endl;
		return -1;		// indicates FAILURE
	}
/*
	// while(cin >> data1 >> data2){
		try{
			if(data1.isbn != data2.isbn){
				throw runtime_error("Data must refer to the same ISBN");
			}

			unsigned totalCount = data1.units_sold + data2.units_sold;
			double totalRevenue = data1.revenue + data2.revenue;
			
			// print ISBN, total sold, total revenue, average-price-per-book
			std::cout << data1.isbn << " " << totalCount << " " << totalRevenue << " ";
			if (totalCount != 0){
				std::cout << totalRevenue/totalCount << std::endl;
			}
			else{
				std::cout << "(no sales)" << std::endl;
			}
			return 0;		// indicates SUCCESS
		} catch (runtime_error err){
			cout << err.what()
				<< "\nTry Again? Enter 'y' or 'n'" << endl;
			char response;
			cin >> response;
			if(!cin || response == 'n'){
				// break;		// must be inside a loop 
				return -1;
			}
		}
	// }
*/
}

void updatedSales(){
	Sales_data total;
	if(read(cin, total)){
		Sales_data trans;
		while(read(cin, trans)){
			if(trans.isbn() == total.isbn()){
				total.combine(trans);
			}else{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	} else{
		cerr << "No Data!!!" << endl;
	}
}





































