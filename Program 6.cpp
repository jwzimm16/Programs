#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Color
{
public:
	string color;
	int r, g, b;

	void Setup(const string& newColor, int newR, int newG, int newB)
	{
		color = newColor;
		r = newR;
		g = newG;
		b = newB;
	}
};

struct Type
{
public:
	string name;

	void Setup(const string& newName)
	{
		name = newName;
	}
};

struct Clothing
{
public:
	string name;
	Color* ptrColor;
	Type* ptrType;

	void Setup(const string& newName, Color* newPtrColor, Type* newPtrType)
	{
		name = newName;
		ptrColor = newPtrColor;
		ptrType = newPtrType;
	}
};

struct Outfit
{
public:
	string name;
	Clothing* ptrHead;
	Clothing* ptrTop;
	Clothing* ptrBottom;

	Outfit()
	{
		ptrHead = NULL;
		ptrTop = NULL;
		ptrBottom = NULL;
	}
};

int main()
{
	Type allTypes[3];
	Color allColors[8];
	Clothing allClothes[9];
	Outfit outfit;

	allTypes[0].Setup("head");
	allTypes[1].Setup("top");
	allTypes[2].Setup("bottom");

	allColors[0].Setup("red", 255, 0, 0);
	allColors[1].Setup("green", 0, 255, 0);
	allColors[2].Setup("blue", 0, 0, 255);
	allColors[3].Setup("yellow", 255, 255, 0);
	allColors[4].Setup("magenta", 255, 0, 255);
	allColors[5].Setup("cyan", 0, 255, 255);
	allColors[6].Setup("black", 255, 255, 255);
	allColors[7].Setup("white", 0, 0, 0);

	allClothes[0].Setup("Baseball cap", &allColors[0], &allTypes[0]);
	allClothes[1].Setup("Top hat", &allColors[1], &allTypes[0]);
	allClothes[2].Setup("Scarf", &allColors[2], &allTypes[0]);
	allClothes[3].Setup("T-shirt", &allColors[3], &allTypes[1]);
	allClothes[4].Setup("Blouse", &allColors[4], &allTypes[1]);
	allClothes[5].Setup("Button-up Shirt", &allColors[5], &allTypes[1]);
	allClothes[6].Setup("Jeans", &allColors[6], &allTypes[2]);
	allClothes[7].Setup("Skirt", &allColors[7], &allTypes[2]);
	allClothes[8].Setup("Cargo Shorts", &allColors[0], &allTypes[2]);

	while (true)
	{
		while (true)
		{					
			for (int i = 0; i < 9; i++) {
				cout << i << ". " << allClothes[i].name << ", " << allClothes[i].ptrColor->color << ", " << allClothes[i].ptrType->name << endl;
			}

			cout << endl << "Select a clothing item: ";
			int choice;
			cin >> choice;

			if (choice < 0 || choice > 8) {
				break;
			}				
			else if (allClothes[choice].ptrType->name == "head") {
				outfit.ptrHead = &allClothes[choice];
				cout << endl;
			}
			else if (allClothes[choice].ptrType->name == "top") {
				outfit.ptrTop = &allClothes[choice];
				cout << endl;
			}
			else if (allClothes[choice].ptrType->name == "bottom") {
				outfit.ptrBottom = &allClothes[choice];
				cout << endl;
			}
		}

		cout << endl;
		cout << "Name of outfit: ";
		cin >> outfit.name;

		string fname = outfit.name + ".txt";
		ofstream output(fname);

		output << outfit.name << endl;

		if (outfit.ptrBottom == NULL) {
			output << "Bottom: Nude" << endl;
		}
		else {
			output << outfit.ptrBottom->name << " ("
				<< outfit.ptrBottom->ptrColor->r << ", "
				<< outfit.ptrBottom->ptrColor->g << ", "
				<< outfit.ptrBottom->ptrColor->b << ")"
				<< endl;
		}

		if (outfit.ptrHead == NULL) {
			output << "Head: Nude" << endl;
		}
		else {
			output << outfit.ptrHead->name << " ("
				<< outfit.ptrHead->ptrColor->r << ", "
				<< outfit.ptrHead->ptrColor->g << ", "
				<< outfit.ptrHead->ptrColor->b << ")"
				<< endl;
		}

		if (outfit.ptrTop == NULL) {
			output << "Top: Nude" << endl;
		}
		else {
			output << outfit.ptrTop->name << " ("
				<< outfit.ptrTop->ptrColor->r << ", "
				<< outfit.ptrTop->ptrColor->g << ", "
				<< outfit.ptrTop->ptrColor->b << ")"
				<< endl;
		}

		output.close();

		char newOutfit;
		cout << endl << "Would you like to create another outfit? (y/n) ";
		cin >> newOutfit;
		cout << endl;

		if (newOutfit == 'n') {
			break;
		}
	}

	return 0;
}
