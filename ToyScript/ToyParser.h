#pragma once
#include "Node.h"
#include "Lexer.h"


class ToyParser
{
public:
	ToyParser(std::vector<Token> tokens);

	void Advance();
	Node* Parse();

	Node* Expr();
	Node* Term();
	Node* Factor();

	void Dispose(void* obj);
private:
	std::vector<Token> m_Tokens;
	int m_CurrentIndex = 0;
	Token m_CurrentToken = m_Tokens[0];
};

