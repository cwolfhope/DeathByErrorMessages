#include <iostream>
#include <string>
#include <fstream>
#include "LinkedStack.cpp"

main(){
	std::string fileName;
	std::string lineData;
	std::string itemName;
	
	LinkedStack<int>* bidStack = new LinkedStack<int>();
	
	std::cout << "Enter a file name ending in \".txt\" : ";
	std::cin >> fileName;
	
	std::ifstream inputFile(fileName);
	
	if(inputFile.is_open()){
		
		getline(inputFile, itemName);
		
		while(getline(inputFile, lineData)){
			if(stoi(lineData) > bidStack->peek())
				bidStack->push(stoi(lineData));
		}
	}
	else{
		std::cout << "Error. File did not open properly." << std::endl;
	}
	
	inputFile.close();
}
