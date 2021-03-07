// ToyScript.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <typeinfo>
#include "Lexer.h"
#include "ToyParser.h"
#include "Intepreter.h"
#define LOG_TOKEN 0
int main()
{
	std::string input;

	while (true) 
	{
		std::cout << "Calc > ";
		std::getline(std::cin, input);
		Lexer lexer(input);
		
		try
		{
			std::vector<Token> tokens = lexer.GenerateTokens();
			ToyParser parser(tokens);

#ifdef LOG_TOKEN
			for (auto i = tokens.begin(); i != tokens.end(); ++i)
				std::cout << (*i).ToString() << ' ' << "\n";
			std::cout << "\n";
#endif // LOG_TOKEN

			Node* tree = parser.Parse();
			Intepreter intpreter;

			std::cout << tree->ToString() << "\n";

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
    std::cout << "Hello World!\n";
}