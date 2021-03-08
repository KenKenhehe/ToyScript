// ToyScript.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include "Lexer.h"
#include "ToyParser.h"
#include "Intepreter.h"
//#define LOG_TOKEN 0
//#define SINGLE_LINE_PROCESS
void Execute(const std::string& line);

int main(int argc, char* argv[])
{
	std::ifstream file;
	if (argv[1] == nullptr) 
	{
		// if command line argument is missing, use the defalut text file to demostrate the calculation
		file = std::ifstream("D:\\MyOwnPL\\ToyScript\\Arithmitic.txt");
	}
	else 
	{
		file = std::ifstream(argv[1]);
	}
	std::string line;

	while (std::getline(file, line)) 
	{
		Execute(line);
	}

	int i = 0;

#ifdef SINGLE_LINE_PROCESS

	std::string input;
	while (true) 
	{
		std::cout << "Calc > ";
		std::getline(std::cin, input);
		Execute(input);
	}

#endif // SINGLE_LINE_PROCESS
}

void Execute(const std::string& text) 
{
	Lexer lexer(text);

	try
	{
		std::vector<Token> tokens = lexer.GenerateTokens();
		Parser parser(tokens);

#ifdef LOG_TOKEN
		for (auto i = tokens.begin(); i != tokens.end(); ++i)
			std::cout << (*i).ToString() << ' ' << "\n";
		std::cout << "\n";
#endif // LOG_TOKEN

		Node* tree = parser.Parse();
		Intepreter intpreter;

		//std::cout << tree->ToString() << "\n";

		Value* value = intpreter.Visit(tree);

		if (value != nullptr)
		{
			std::cout << value->GetValue() << "\n";
		}

		delete tree;
	}
	catch (std::string exp)
	{
		std::cout << exp << std::endl;
	}
}