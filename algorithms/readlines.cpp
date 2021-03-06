/*
	Copyright @vinaykumar2491
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

using std::begin;
using std::end;

int main(){

	//----------------------------------------------------------------------------
	const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	string letterGrade;
	int grade ;
	cout << "Grades please: " ;
	cin >> grade;
	if(grade < 60){
		letterGrade = scores[0];
		cout << letterGrade << endl;
	}else{
		letterGrade = scores[(grade-50)/10];
		if(grade != 100){
			if(grade % 10 > 7){
				letterGrade += '+';
			}else if(grade % 10 < 3){
				letterGrade += '-';
			}
		}
		cout << letterGrade << endl;
	}
	

	// reading per word. Starting and ending whitespaces are ignored
//	string s1, s2;					// Empty strings
//	cin >> s1 >> s2;				// reading first two words separated by 'whitespace' character in a single line
//	cout << s1 << s2 << endl;		// printing the read words
//	
	// reading a complete line. Starting and ending whitespaces are NOT ignored
	string m_line;
	getline(cin, m_line);
	cout << m_line << endl;
	
	//Capitalize the line using iterator
	for(auto iter= m_line.begin(); iter != m_line.end() && !isspace(*iter); ++iter){
		*iter = toupper(*iter);
	}
	cout << m_line << endl;
	
	//----------------------------------------------------------------------------
	const string hexdigits = "0123456789ABCDEF";
	string result;						// holds the hexif'ed string
	string::size_type n;				// Holds the numbers from input
	
	cout << "Enter a series of numbers b/w 0 and 15 "
		 << "separated by SPACES. Hit ENTER when done: "
		 << endl;
	while (cin >> n){					// checks if the input is empty or reached EOF
		if(n < hexdigits.size()){		// checks if the entered integer is in the range [0,15]
			result += hexdigits[n];		// fetches the n'th value from hexdigits string 
		}
	}
	
	cout << result << endl;	
	
	//----------------------------------------------------------------------------
	//  pointers as iterators
	// finding the 1st -ve eleemnt in an array of int
	
	int m_array[] = {61, 32, 0, 98, -19, -53, 90};			// when we list initialize an array, we can omit the dimension
	int *ptr_beg = begin(m_array);
	int *ptr_end = end(m_array);
	
	while(ptr_beg != ptr_end && *ptr_beg >= 0){
		++ptr_beg;
		cout << *ptr_beg << endl;
	}
	
	//----------------------------------------------------------------------------
	// using pointers, write a program to set the elements in an array to 0
	for(int *ptr = begin(m_array); ptr != end(m_array); ++ptr){
		*ptr = 0;
		cout << *ptr << " ";
	}
	cout << endl;
	
	//----------------------------------------------------------------------------
	// Comparing two arrays and two vectors
	
	cout << "Comparing two arrays and two vetors respectively!!" << endl;
	
	int m_array1[] = {1, 2, 3, 4, 5, 6};					// when we list initialize an array, we can omit the dimension
	int m_array2[] = {1, 3, 4, 5, 6, 7};
	vector<int> m_vec1{1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> m_vec2{1, 2, 14, 15, 16, 17, 17, 19};
	
	int *begA1 = begin(m_array1);
	int *endA1 = end(m_array1);
	int *begA2 = begin(m_array2);
	int *endA2 = end(m_array2);
	auto begV1 = m_vec1.begin();
	auto endV1 = m_vec1.end();
	auto begV2 = m_vec2.begin();
	auto endV2 = m_vec2.end();
	
	if((endA1-begA1) == (endA2-begA2)){				// checking if the arrays are of same size
		while(begA1 != endA1 && *begA1 == *begA2){
			cout << "Arrays: " << *begA1 << " = " << *begA2 << endl;
			++begA1;
			++begA2;
		cout << "Arrays were of equal size and the results of their equality are above." << endl;			
		}
	}else{
		cout << "The two Arrays are NOT of same size!!" << endl;
	}
	
	if((endV1-begV1) == (endV2-begV2)){				// checking if the vectors are of same size
		while(begV1 != endV1 && *begV1 == *begV2){
			cout << "Vectors: " << *begV1 << " = " << *begV2 << endl;
			++begV1;
			++begV2;
		}
		cout << "Vectors were of equal size and the results of their equality are above." << endl;
	}else{
		cout << "The two Vectors are NOT of same size!!" << endl;
	}
	
	//----------------------------------------------------------------------------
	const char carray[] = {'r', 'u', 's', 't', 'o', 'm'};		// when we list initialize an array, we can omit the dimension
	const char *cptr = carray;
	while(*cptr){
		cout << *cptr << endl;
		++cptr;	
	}
	
	//----------------------------------------------------------------------------
	// Initialize a vector from an array of ints
	const int m_array3[] = {1, 21, 32, 76, 49, 0, -1, 390, -132};
	vector<int> m_vec3(begin(m_array3), end(m_array3));
	
	for(auto m_iter3 : m_vec3){						// using range for statement
		cout << m_iter3 << ", ";
		++m_iter3;
	}
	cout << endl;
	
	// copy a vector of ints into an array of ints
	// const auto m_size_vec3 = (m_vec3.end() - m_vec3.begin());			// can't be used to define the size of the array.
	const int m_size = 9;
	int m_array4[m_size];
	
	int *endA4 = end(m_array4);		// pointer to the off-the-end of array
	auto m_begV3 = m_vec3.begin();
	auto m_endV3 = m_vec3.end();
	
	
	for(int *ptr = begin(m_array4); ptr != endA4; ++ptr){
		*ptr = *m_begV3;
		++m_begV3;
		cout << *ptr << ". ";
	}
	cout << endl;
	
	//----------------------------------------------------------------------------
	// multidimensional arrays
	int m_multiArray[2][3] = {
		{1, 2, 3},
		{11, 12, 13}
	};
	
	//range for 
	for(auto ptrA = m_multiArray; ptrA != m_multiArray + 2; ++ptrA){
		for(auto ptrB = *ptrA; ptrB != *ptrA + 3; ++ptrB){
			cout << *ptrB << ", ";
		}
		cout << endl;
	}
	
	for(auto ptrC = begin(m_multiArray); ptrC != end(m_multiArray); ++ptrC){
		for(auto ptrD = begin(*ptrC); ptrD != end(*ptrC); ++ptrD){
			cout << *ptrD <<", ";
		}
		cout << endl;
	}

	//----------------------------------------------------------------------------
	vector<string> m_vec5{"Hi", "", "Mr", "Rustom", "Potter.", "My name is Prithviraj."};

	// range for loop
	for(const auto &str : m_vec5){		// const is used to avoid writing to str; reference is used b'coz we don't need to copy str
		cout << str;

		// in this if-statement, we reply on short-circuit evaluation of "logical OR (||)" operator to ensure that
		// we subscript str only if str is not empty

		if (str.empty() || str[str.size() - 1] == '.')		// use '.' instead of "." b'coz C++ forbids comparision b/w pointers and integers
		{
			cout << endl;
		}else{
			cout << " ";
		}
	}





	//----------------------------------------------------------------------------
	return 0;						// SUCCESS	
}























