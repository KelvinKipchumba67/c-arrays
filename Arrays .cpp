#include <iostream>
#include <string>
#include <limits>//using it to remove buffering as the program accepts input
#include <iomanip>//using it for the printing the receipt at the end
using namespace std;
int main (){
	int size=10;//used this to allow easy manipulation of the arrays sizes and loops
	string names[size];
	float prices[size];
	int quantity[size];
	
	cout<<"For each item give its name, price and quantity respectively"<<endl;
	for(int i=0;i<size;i++){
		cout<<"Item : "<<i<<endl;
		
		cout<<"Name: ";
		getline(cin, names[i]);
		
		cout<<"Price: ";
		cin>>prices[i];
		
		cout<<"Quantity: ";
		cin>>quantity[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	}
	float grand_total=0;
	for(int j=0;j<size;j++){
		grand_total =grand_total + prices[j]*quantity[j];
	}	
	// Table header
    // setw(15) reserves 15 spaces.left aligns text to left,'right'to right.
    cout << left  << setw(20) << "Item Name"
         << right << setw(10) << "Price" 
         << right << setw(10) << "Qty" 
         << right << setw(15) << "Total (PxQ)" << endl;
    cout<<"--------------------------------------"<<endl;      
// Looping through arrays to print rows and calculate totals
    for(int i = 0; i < size; i++) {
        float rowTotal = prices[i] * quantity[i];
        // Print the Row
        cout << left  << setw(20) << names[i] 
             << right << setw(10) << fixed << setprecision(2) << prices[i] 
             << right << setw(10) << quantity[i] 
             << right << setw(15) << fixed << setprecision(2) << rowTotal << endl;
    }
    cout<<"--------------------------------------"<<endl;
    cout << right << setw(40) << "Grand Total = " << grand_total << endl;
     
	return 0;

}

