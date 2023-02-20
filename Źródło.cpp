#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

long int counter = 0;

class BST {
	string data;
	int height;
	BST* left, *right;

public:
	BST();
	BST(string);
	BST* Insert(BST*, string);
	int getHeight(BST* root);
	void deleteBinaryTree(BST*& root);
	void display(BST* root);
	void Search(BST* root, string data);
	BST* Min(BST* root);
	BST* Delete(BST* root, string value);

};

BST::BST() : data(""), height(0), left(NULL), right(NULL) {}

BST::BST(string value) {
	data = value;
	height = 0;
	left = right = NULL;
}

BST* BST::Insert(BST* root, string value) {
	if (!root) {
		return new BST(value);
		//counter++;
	}
	if (value <= root->data) {
		root->left = Insert(root->left, value);
		//counter++;
	}
	else if (value > root->data) {
		root->right = Insert(root->right, value);
		//counter++;
	}

	return root;
}

int BST::getHeight(BST* root) {
	if (!root) return 0;
	else {
		int leftHeigth = getHeight(root->left);
		int rightHeigth = getHeight(root->right);

		if (leftHeigth >= rightHeigth) return leftHeigth + 1;
		else return rightHeigth + 1;
	}
}

void BST::deleteBinaryTree(BST*& root)
{
	if (root == nullptr) {
		return;
	}

	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);

	delete root;

	root = nullptr;
}

void BST::display(BST* root)
{
	if (root != NULL)
	{
		display(root->left);
		cout << root->data << " ";
		display(root->right);
	}
}

void BST::Search(BST* root, string data)
{
	int depth = 0;
	BST* temp = new BST;
	temp = root;
	// Run the loop untill temp points to a NULL pointer.
	while (temp != NULL)
	{
		depth++;
		if (temp->data == data)
		{
			//counter++;
			//cout << "\nData found at depth: " << depth;
			return;
		}
		// Shift pointer to left child.
		else if (temp->data > data) {
			//counter++;
			temp = temp->left;
		}
			
		// Shift pointer to right child.
		else {
			//counter++;
			temp = temp->right;
		}
			
	}

	//cout << "\n Data not found";
	return;
}

BST* BST::Min(BST* root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

BST* BST::Delete(BST* root, string value)
{

	if (root == NULL)
	{
		counter++;
		return root;
	}
		
	else if (value < root->data)
	{
		counter++;
		root->left = Delete(root->left, value);
	}
	else if (value > root->data)
	{
		counter++;
		root->right = Delete(root->right, value);
	}

	// Node deletion
	else
	{
		// Leaf Node
		if (root->left == NULL && root->right == NULL)
		{
			counter++;
			delete root;
			root = NULL;
			return root;
		}
		//one child
		else if (root->left == NULL)
		{
			counter++;
			struct BST* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if (root->right == NULL)
		{
			counter++;
			struct BST* temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		//child
		else
		{
			counter++;
			struct BST* temp = Min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;

}

int main() {
	setlocale(LC_CTYPE, "Polish");
	// PART 1 //
	/*
	string* list;
	list = new string[4];
	list[0] = "OSA";
	list[1] = "KOS";
	list[2] = "AS";
	list[3] = "LAS";

	BST bst, * root = NULL;
	int v, h;
	srand(time(NULL));
	for (int j = 100; j <= 10000; j += 100) {
		for (int i = 0; i < j; i++) {
			v = rand() % 4;
			if (i == 0) root = bst.Insert(root, list[v]);
			else bst.Insert(root, list[v]);
		}
		//h = bst.getHeight(root);
		//cout << h << endl;
		//bst.Search(root, "AS");
		bst.Delete(root, "AS");
		cout << counter << endl;
		bst.deleteBinaryTree(root);
		counter = 0;
	}
	*/

	// PART 2 //
	/*
	char* listOfLetters;
	char c;
	listOfLetters = new char[35];
	int k = 0;
	for (int i = 97; i <= 122; i++) {
		c = i;
		listOfLetters[k] = c;
		k++;
	}

	// 185 230 234 179 241 243 156 159 191 - polskie znaki
	listOfLetters[26] = (char)185;
	listOfLetters[27] = (char)230;
	listOfLetters[28] = (char)234;
	listOfLetters[29] = (char)179;
	listOfLetters[30] = (char)241;
	listOfLetters[31] = (char)243;
	listOfLetters[32] = (char)156;
	listOfLetters[33] = (char)159;
	listOfLetters[34] = (char)191;
	

	BST bst, * root = NULL;
	int v;
	long int h;
	//string word = "";


	string filename("text2.txt");
	vector<string> words;
	string word;

	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Could not open the file - '"
			<< filename << "'" << endl;
		return EXIT_FAILURE;
	}

	while (input_file >> word) {
		words.push_back(word);
	}

	srand(time(NULL));
	for (int j = 100; j <= 10000; j += 100) {
		for (int i = 0; i < j; i++) {


			//for (int k = 0; k < 4; k++) {
			//	v = rand() % 35;
			//	word += listOfLetters[v];
			//}

			word = words[i];
			if (i == 0) root = bst.Insert(root, word);
			else bst.Insert(root, word);
			//cout << word << endl;
			//word = "";
		}
		//h = bst.getHeight(root);
		//cout << h << endl;
		//bst.Search(root, "sie");
		bst.Delete(root, "sie");
		cout << counter << endl;
		bst.deleteBinaryTree(root);
		counter = 0;
	}
	*/

	// PART 3 //
	///*
	string filename("text.txt");
	vector<string> words;
	string word;

	//int counter = 0;
	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Could not open the file - '"
			<< filename << "'" << endl;
		return EXIT_FAILURE;
	}

	while (input_file >> word) {
		words.push_back(word);
	}	
	
	BST bst, * root = NULL;
	int v, h;
	srand(time(NULL));
	for (int j = 100; j <= 10000; j += 100) {
		for (int i = 0; i < j; i++) {
			word = words[i];
			if (i == 0) root = bst.Insert(root, word);
			else bst.Insert(root, word);
		}
		//h = bst.getHeight(root);
		//cout << h << endl;
		//bst.Search(root, "zauwa¿y³");
		bst.Delete(root, "jutro");
		cout << counter << endl;
		bst.deleteBinaryTree(root);
		counter = 0;
	}
	
	input_file.close();
	//*/

	return 0;
}