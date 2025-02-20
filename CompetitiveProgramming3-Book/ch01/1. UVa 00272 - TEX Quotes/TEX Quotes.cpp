/*

 @ Author: Galleto  
 
 @ Contact: plaguepatient@outlook.com
 
 @ Date: 8 / 2 / 2025

 #  UVa 00272 - TEX Quotes # 

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	// Obviously, this is our line //
    string line; 
    
    // Variable to toggle between opening and closing quotes //
    bool openQuote = true; 

    // Read input line by line until end of input //
    while (getline(cin, line)) {
    	// Stores the modified line //
        string output; 

        // Iterate through each character in the line //
        for (char ch : line) {
        	// If a double quote is found //
            if (ch == '"') { 
                if (openQuote) {
                	// Replace with opening quotation marks (``) //
                    output += "``"; 
                } else {
                	// Replace with closing quotation marks ('') //
                    output += "''"; 
                }
                // Toggle the quote state //
                openQuote = !openQuote; 
            } else {
            	// If not a quote, keep the original character //
                output += ch; 
            }
        }
        // I’d say this is super obvious. //
        cout << output << endl; 
    }
     // ;)
    return 0;
}
