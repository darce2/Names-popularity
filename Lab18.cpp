/*
	this program:
	1. reads in 1,000 boy names and 1,000 girl names,
	  along with their numeric popularities, into
	  4 arrays (2 for boys, 2 for girls)
	2. as long as user wishes, displays a menu allowing
	  user to:
	  a. input a boy name; the popularity of that name
	     is displayed if known (in the boy name array);
	 otherwise, "Unknown" is displayed
           b. input a girl name; the popularity of that name
	     is displayed if known (in the girl name array);
	 otherwise, "Unknown" is displayed
	  c. exit (quit) the program
*/

#include <iostream>
#include <fstream>
#include <array>
#include <string>

#include "Array_Functions.h"

using namespace std;

// Global Declarations

const int ARRAY_SIZE = 1000;
const string BOY_NAMES = "boynames.txt";
const string GIRL_NAMES = "girlnames.txt";

// Function Template Declarations

// fills up the name (string) and popularity (int) arrays
//   in tandem from the given input stream
//  *** FUNCTION TEMPLATE DEFINITION MUST BE WRITTEN IN Array_Functions.h ***
template<size_t S>
void fillArrays(array<string, S>& names, array<int, S>& popularities, ifstream& input);
// looks up the name in the names (string) array; if it's there,
//   retrieves and returns the popularity from the popularity array
//  *** FUNCTION TEMPLATE DEFINITION MUST BE WRITTEN IN Array_Functions.h ***
template<size_t S>
int findPopularity(array<string, S> names, array<int, S> pops, string name);

// Function Declarations

// Displays menu, and returns user's choice
char showMenu();
// Displays the name, type ("boy" or "girl"), popularity, and
//  a message based on the given popularity
//  *** FUNCTION DEFINITION MUST BE WRITTEN NEAR THE BOTTOM OF THIS FILE ***
void showResults(string name, string type, int popularity);

int main()
{
	// arrays for boy & girl names and popularities
	array<string, ARRAY_SIZE> boyNames, girlNames;
	array<int, ARRAY_SIZE> boyPops, girlPops;

	// input streams
	ifstream boyInput, girlInput;

	// menu choice
	char choice;

	// used for popularity lookup
	string name;
	int popularity;

	// set up input stream
	boyInput.open(BOY_NAMES.c_str());

	if (boyInput.fail())
	{
	cerr << "\nBoy input file failed to open; exiting.\n";
	exit(1);
	}

	girlInput.open(GIRL_NAMES.c_str());

	if (girlInput.fail())
	{
	cerr << "\nGirl input file failed to open; exiting.\n";
	exit(1);
	}

	// Fill the boy and girl arrays from the input streams
	fillArrays(boyNames, boyPops, boyInput);
	fillArrays(girlNames, girlPops, girlInput);

	// show user menu, and respond to user's choice
	do
	{
	choice = showMenu();

	switch (choice)
	{
	case 'B':
	case 'b':
	cout << "\nWhat is the boy's name? ";
	cin >> name;

	popularity = findPopularity(boyNames, boyPops, name);

	showResults(name, "boy", popularity);
	break;
	case 'G':
	case 'g':
	cout << "\nWhat is the girl's name? ";
	cin >> name;

	popularity = findPopularity(girlNames, girlPops, name);

	showResults(name, "girl", popularity);
	break;
	case 'Q':
	case 'q':
	// end the program
	break;
	default:
	cerr << "\nUnknown Menu Choice.\n";
	} // end switch
	} while (choice != 'Q' && choice != 'q');

	// close the input streams
	boyInput.close();
	girlInput.close();

	// end of program
	return 0;
} // end main

/*
	showMenu -> char

	Displays a menu of options, and returns user's choice
*/
char showMenu()
{
	char choice;

	cout << "\nPick your option:\n"
	<< "B/b: Find a boy name's popularity\n"
	<< "G/g: Find a girl name's popularity\n"
	<< "Q/q: Exit the program.\n\n"
	<< "Enter your choice: ";
	cin >> choice;

	return choice;

} // end showMenu

/*
	showResults : string, string, int
	
	function is given a name (string), its (string) type ("boy" or "girl'),
	  and its popularity (int)
	Function then displays the name, popularity, and a message:
	popularity > 20,000 -> "Wow! Really Popular!"
	15,000 < popularity <= 20,000 -> "Quite Popular"
	10,000 < popularity <= 15,000 -> "Popular"
	5,000 < popularity <= 10,000 -> "Not So Popular"
	1,000 < popularity <= 5,000 -> "A Bit Rare"
	0 <= popularity <= 1,000 -> "Wow, Rare!"
	otherwise -> "Unknown";

	*** TO DO: WRITE FUNCTION DEFINITION ***
 */
void showResults(string name, string type, int popularity)
{
	cout << "The name " << name<< " has a ";

	if( popularity > 20000 )
	{
		cout << "popularity > "<< popularity << " -> Wow! Readlly Popular!"; 
	}
	else if ( popularity > 15000 && popularity <= 20000)
	{
		cout << "15000 < " << popularity << " <= 20,000 -> Quite Popular"; 
	}
	else if ( popularity > 10000 && popularity <= 15000)
	{
		cout << "10000 < " << popularity << " <= 15,000 -> Popular"; 
	}
	else if ( popularity > 5000 && popularity <= 10000 )
	{
		cout << "5000 < " << popularity << " <= 10,000 -> Not So Popular"; 
	}
	else if ( popularity > 1000 && popularity <= 5000 )
	{
		cout << "1000 < " << popularity << " <= 5,000 -> A Bit Rare"; 
	}
	else if ( popularity > 0 && popularity <= 1000)
	{
		cout << "0 <= " << popularity << " <= 1,000 -> Wow, Rare!"; 
	}

}
