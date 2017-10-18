#pragma once

#include <fstream>
#include <string>
#include <algorithm>
#include "SearchTree.h"

using namespace std;
SearchTree<Entry<string, string> >* buildBST_fromDatafile(const std::string& filename) {
	std::ifstream f(filename.c_str());
	if (!f)
		throw std::runtime_error("cannot open data file");

	std::string s;

	getline(f, s);
	std::string magic("CPSC131 Project3 raw data file");
	if (!f || !std::equal(magic.begin(), magic.end(), s.begin()))
		throw std::runtime_error("incorrect data file");
	getline(f, s);

	std::string firstName, movie;

	SearchTree<Entry<string, string>> *bst = new SearchTree<Entry<string, string>>;

	// TO DO: implement the creation of a binary search tree
	for (int i = 3; i < 174; i++)
	{
		getline(f, s);
		firstName = s.substr(0, s.find(",")); // name = beginning to ','
		movie = s.substr(s.find(",") + 1, s.find('\n')); //movie = whatever between ',' and '\n'
		movie.erase(std::remove(movie.begin(), movie.end(), '\n'), movie.end()); //trying to remove '\n'
		bst->insert(firstName, movie); //stick it in the tree
		//bst->insert(s.substr(0, s.find(",")), s.substr(s.find(",") + 1, s.find('\n')));
	}
	f.close();
	return bst;
}

// TO DO: You need to implement a function to print a singly linked list in reverse order
void printInReverseOder(SNode<Entry<string, string> >* node)
{
	SNode<Entry<string, string> >* temp = node;
	while (temp->getnext())
	{
		cout << temp->getElem().key() << ", " << temp->getElem().value()<<endl;
		temp = temp->getnext();
	}

}
//test
