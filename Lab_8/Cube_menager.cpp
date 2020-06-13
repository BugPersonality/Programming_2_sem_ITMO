#include "Cube_menager.h"
#include<iostream>
using namespace std;

void Cube_menager::save_side(const Colors(&face)[3][3], const string& faceName, const string& filename)
{
	ofstream output;
	output.open(filename, std::ios_base::app);

	output << faceName << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			output << static_cast<int>(face[i][j]) << ' ';
		}

		output << endl;
	}
	if (!output.good())
	{
		throw runtime_error("Problem with file");
	}
}

void Cube_menager::load_side(Colors(&face)[3][3], const string& filename)
{
	ifstream input;
	input.open(filename);

	unsigned int value;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			input >> value;

			face[i][j] = static_cast<Colors>(value);
		}
	}

	input.close();
}

void Cube_menager::cout_side(const Colors(&face)[3][3], const string& faceName)
{
	cout << faceName << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << static_cast<int>(face[i][j]) << ' ';
		}

		cout << endl;
	}
}

Cube_menager::Cube_menager(int i)
{
	i = 1;
}

void Cube_menager::save_solve(const string& filename)
{
	ofstream outfile;

	outfile.open(filename);

	vector<string> solve;
	vector<string> _solve;

	solve = cube.get_Svector();

	reverse(solve.begin(), solve.end());

	for (auto item : solve)
	{
		if (item == "F")
		{
			_solve.push_back("N");
		}
		else if (item == "N")
		{
			_solve.push_back("F");
		}
		else if (item == "B")
		{
			_solve.push_back("M");
		}
		else if (item == "M")
		{
			_solve.push_back("B");
		}
		else if (item == "U")
		{
			_solve.push_back("Z");
		}
		else if (item == "Z")
		{
			_solve.push_back("U");
		}
		else if (item == "D")
		{
			_solve.push_back("X");
		}
		else if (item == "X")
		{
			_solve.push_back("D");
		}
		else if (item == "L")
		{
			_solve.push_back("C");
		}
		else if (item == "C")
		{
			_solve.push_back("L");
		}
		else if (item == "R")
		{
			_solve.push_back("V");
		}
		else if (item == "V")
		{
			_solve.push_back("R");
		}
	}

	for (auto item : _solve)
	{
		outfile << item << endl;
	}

	cout << "Saved successfully!" << endl;
}

void Cube_menager::save_invert_solve(const string& filename)
{
	ofstream outfile;

	outfile.open(filename);

	vector<string> solve;

	solve = cube.get_Svector();

	for (auto item : solve)
	{
		outfile << item << endl;
	}

	cout << "Saved successfully!" << endl;
}

void Cube_menager::load_from_file(const string& filename)
{
	State newState;
	string faceName;

	ifstream input;
	input.open(filename);

	for (int i = 0; i < 6; i++)
	{
		input >> faceName;

		if (faceName == "FRONT")
		{
			load_side(newState.Front, filename);
		}
		else if (faceName == "BACK")
		{
			load_side(newState.Back, filename);
		}
		else if (faceName == "UP")
		{
			load_side(newState.Up, filename);
		}
		else if (faceName == "DOWN")
		{
			load_side(newState.Down, filename);
		}
		else if (faceName == "LEFT")
		{
			load_side(newState.Left, filename);
		}
		else if (faceName == "RIGHT")
		{
			load_side(newState.Right, filename);
		}
	}

	cube.setState(newState);

	input.close();
}

void Cube_menager::save_state(const string& filename)
{
	State buffer = cube.get_state();

	save_side(buffer.Front, "FRONT", filename);
	cout << "FRONT side saved!" << endl;

	save_side(buffer.Back, "BACK", filename);
	cout << "BACK side saved!" << endl;

	save_side(buffer.Up, "UP", filename);
	cout << "UP side saved!" << endl;

	save_side(buffer.Down, "DOWN", filename);
	cout << "DOWN side saved!" << endl;

	save_side(buffer.Left, "LEFT", filename);
	cout << "LEFT side saved!" << endl;

	save_side(buffer.Right, "RIGHT", filename);
	cout << "RIGHT side saved!" << endl;
}

void Cube_menager::cout_state()
{
	State buffer = cube.get_state();

	cout_side(buffer.Front, "FRONT");

	cout_side(buffer.Back, "BACK");

	cout_side(buffer.Up, "UP");

	cout_side(buffer.Down, "DOWN");

	cout_side(buffer.Left, "LEFT");

	cout_side(buffer.Right, "RIGHT");
}

void Cube_menager::solve_cube()
{
	vector<string> solve;

	solve = cube.get_Svector();

	reverse(solve.begin(), solve.end());

	for (auto item : solve)
	{
		if (item == "F")
		{
			cube._F();
		}
		else if (item == "N")
		{
			cube.F();
		}
		else if (item == "B")
		{
			cube._B();
		}
		else if (item == "M")
		{
			cube.B();
		}
		else if (item == "U")
		{
			cube._U();
		}
		else if (item == "Z")
		{
			cube.U();
		}
		else if (item == "D")
		{
			cube._D();
		}
		else if (item == "X")
		{
			cube.D();
		}
		else if (item == "L")
		{
			cube._L();
		}
		else if (item == "C")
		{
			cube.L();
		}
		else if (item == "R")
		{
			cube._R();
		}
		else if (item == "V")
		{
			cube.R();
		}
	}

	cout << "cube assembled successfully!" << endl;
}



