#pragma once
#include <string>
class Node
{
public:
	virtual std::string ToString() = 0;
};

class NumberNode : public Node 
{
public:
	NumberNode(std::string value) : m_Value(value){}

	 std::string ToString() override { return m_Value; }

	std::string GetValue() { return m_Value; }
private:
	std::string m_Value;
};

class AddNode : public Node 
{
public:
	AddNode(Node* left, Node* right) : 
		m_Left(left), m_Right(right) {}

	std::string ToString() override { return "(" + m_Left->ToString() + " + " + m_Right->ToString() + ")"; }
private:
	Node* m_Left;
	Node* m_Right;
};

class SubstractNode : public Node
{
public:
	SubstractNode(Node* left, Node* right) :
		m_Left(left), m_Right(right) {}

	std::string ToString() override { return "(" + m_Left->ToString() + " - " + m_Right->ToString() + ")"; }
private:
	Node* m_Left;
	Node* m_Right;
};

class MultiplyNode : public Node
{
public:
	MultiplyNode(Node* left, Node* right) :
		m_Left(left), m_Right(right) {}

	std::string ToString() override { return "(" + m_Left->ToString() + " * " + m_Right->ToString() + ")"; }
private:
	Node* m_Left;
	Node* m_Right;
};

class DivideNode : public Node
{
public:
	DivideNode(Node* left, Node* right) :
		m_Left(left), m_Right(right) {}

	std::string ToString() override { return "(" + m_Left->ToString() + " / " + m_Right->ToString() + ")"; }
private:
	Node* m_Left;
	Node* m_Right;
};

class PlusNode : public Node 
{
public:
	PlusNode(Node* node) : m_Node(node){}

	std::string ToString() override { return "(+" + m_Node->ToString() + ")"; }
private:
	Node* m_Node;
};

class MiniusNode : public Node
{
public:
	MiniusNode(Node* node) : m_Node(node) {}

	std::string ToString() override { return "(-" + m_Node->ToString() + ")"; }
private:
	Node* m_Node;
};

