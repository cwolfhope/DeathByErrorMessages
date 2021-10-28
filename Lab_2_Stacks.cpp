#include <iostream>
#include <string>
#include <fstream>
#include "LinkedStack.h"

main(){
	std::string fileName;
	std::string lineData;
	std::string itemName;
	int* stackItemPtr;
	int stackItem;
	
	LinkedStack<int>* bidStack = new LinkedStack<int>();
	
	fileName = "ItemBid.txt";
	//std::cout << "Enter a file name ending in \".txt\" : ";
	//std::cin >> fileName;
	
	std::ifstream inputFile(fileName);
	
	if(inputFile.is_open()){
		getline(inputFile, itemName);
		std::cout << itemName << std::endl;
		
		while(getline(inputFile, lineData)){
			//std::cout << "W" << std::endl;
			if(!bidStack->isEmpty()){
				if(stoi(lineData) > bidStack->peek()){
					stackItem = stoi(lineData);
					stackItemPtr = &stackItem;
					bidStack->push(stackItemPtr);
				}
			}
			else if(bidStack->isEmpty()){
				stackItem = stoi(lineData);
				//std::cout << stackItem;
				stackItemPtr = &stackItem;
				std::cout << stackItemPtr;
				//bidStack->push(stackItemPtr);
				bidStack->push(stackItem);
				//std::cout << bidStack->peek() << std::endl;
			}
		}
	}
	else{
		std::cout << "Error. File did not open properly." << std::endl;
	}
	
	std::cout << "The winning bid for " << itemName << " is $" << bidStack->peek() << "." << std::endl;
	
	inputFile.close();
}
