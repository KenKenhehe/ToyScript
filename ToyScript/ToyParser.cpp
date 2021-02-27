#include "ToyParser.h"

ToyParser::ToyParser(std::vector<Token> tokens) : m_Tokens(tokens)
{
	//Create space for token to avoid reallocating space, hence increase performance
	m_Tokens.reserve(tokens.size());

	m_CurrentToken = tokens[m_CurrentIndex];
}

void ToyParser::Advance()
{
	if (m_CurrentIndex < m_Tokens.size() - 1) 
	{
		m_CurrentIndex++;
		m_CurrentToken = m_Tokens[m_CurrentIndex];
	}
	
}

Node* ToyParser::Parse()
{
	if (&m_CurrentToken == nullptr) 
	{
		return nullptr;
	}

	Node* result = Expr();

	/*if (&m_CurrentToken != nullptr) 
	{
		throw "Syntax error";
	}*/

	return result;
}



Node* ToyParser::Expr()
{
	Node* result = (Node*)Term();
	while (
		&m_CurrentToken != nullptr &&
		(m_CurrentToken.GetTokenType() == Token::TokenType::PLUS ||
			m_CurrentToken.GetTokenType() == Token::TokenType::MINUS)
		)
	{
		if (m_CurrentToken.GetTokenType() == Token::TokenType::PLUS)
		{
			Advance();
			Node* right = Term();
			result = new AddNode((Node*)result, right);
		}
		else if (m_CurrentToken.GetTokenType() == Token::TokenType::MINUS)
		{
			Advance();
			Node* right = Term();
			result = new SubstractNode((Node*)result, right);
		}
		
	}

	std::string str = ((Node*)result)->ToString();

	return result;
}

Node* ToyParser::Term()
{
	Node* result = Factor();
	while (
		&m_CurrentToken != nullptr && 
		(m_CurrentToken.GetTokenType() == Token::TokenType::MUL || 
			m_CurrentToken.GetTokenType() == Token::TokenType::DIV)
		)
	{
		if (m_CurrentToken.GetTokenType() == Token::TokenType::MUL) 
		{
			Advance();
			Node* right = (Node*)Factor();
			result = new MultiplyNode((Node*)result, right);
		}
		else if (m_CurrentToken.GetTokenType() == Token::TokenType::DIV)
		{
			Advance();
			Node* right = (Node*)Factor();
			result = new DivideNode((Node*)result, right);
		}
	}

	return result;
}

Node* ToyParser::Factor()
{
	Token currentToken = m_CurrentToken;
	if (m_CurrentToken.GetTokenType() == Token::TokenType::NUMBER) 
	{
		Advance();
		Node* result = new NumberNode(currentToken.GetTokenValue());
		return result;
	}
	else if (m_CurrentToken.GetTokenType() == Token::TokenType::PLUS) 
	{
		Advance();
		Node* result = new PlusNode(Factor());
		return result;
	}

	else if (m_CurrentToken.GetTokenType() == Token::TokenType::MINUS)
	{
		Advance();
		Node* result = new MiniusNode(Factor());
		return result;
	}
	else if (m_CurrentToken.GetTokenType() == Token::TokenType::L_PAREN)
	{
		Advance();
		Node* expr = Expr();
		if (m_CurrentToken.GetTokenType() != Token::TokenType::R_PAREN)
		{
			throw "Expected ')'";
		}
		Advance();
		return expr;
	}

	throw "Syntax Error";
}

void ToyParser::Dispose(void* obj)
{
	delete (Node*)obj;
}

