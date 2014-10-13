// Array_Functions.h

#include <iostream>
#include <fstream>
#include <array>
#include <string>

using namespace std;

// Global Constants

const int NOT_FOUND = -1;

/*
	fillArrays : array<string, S>, array<int, S>, ifstream

	function fills up the name (string) and popularity (int) arrays
	 in tandem from the given input stream

	*** FUNCTION TEMPLATE DEFINITION MUST BE WRITTEN ***
 */
template<size_t S>
void fillArrays(array<string, S>& names, array<int, S>& popularities, ifstream& input)
{
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		input >> names[i] >> popularities[i];
	}//end loop
}


/*
	findPopularity : array<string, S>, array<int, S>, string -> int

	looks up the name in the names (string) array.
	 if it is there, returns the corresponding popularity
	   from the popularities (int) array
	 otherwise, returns NOT_FOUND

	*** FUNCTION TEMPLATE DEFINITION MUST BE WRITTEN ***
*/
template<size_t S>
int findPopularity(array<string, S> names, array<int, S> pops, string name)
{
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		if ( names[i] == name)
		{
			return pops[i];
		}
		
	}// end for loop
	
	return NOT_FOUND;


}