#pragma once

#include "cube_logic.h"

class Cube_menager
{
private:
	
	void save_side(const Colors(&face)[3][3], const string& faceName, const string& filename);
	void load_side(Colors(&face)[3][3], const string& filename);
	void cout_side(const Colors(&face)[3][3], const string& faceName);

public:
	Cube cube;
	Cube_menager(int i);
	void save_solve(const string& filename);
	void save_invert_solve(const string& filename);
	void load_from_file(const string& filename);
	void save_state(const string& filename);
	void cout_state();
	void solve_cube();
};

