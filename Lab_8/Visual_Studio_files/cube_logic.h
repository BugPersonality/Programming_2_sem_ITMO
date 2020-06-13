#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <algorithm>
#include <iterator>

using namespace std;

enum  class Colors
{
	RED = 0, 
	GREEN = 1, 
	YELLOW = 2,
	BLUE = 3,
	WHITE =	4,
	ORANGE = 5,
};

struct State
{
	Colors Front[3][3];
	Colors Back[3][3];
	Colors Up[3][3];
	Colors Down[3][3];
	Colors Left[3][3];
	Colors Right[3][3];
};

const State defaultState
{		
	{
		{Colors::WHITE, Colors::WHITE, Colors::WHITE},
		{Colors::WHITE, Colors::WHITE, Colors::WHITE}, //front
		{Colors::WHITE, Colors::WHITE, Colors::WHITE}
	},

	{
		{Colors::YELLOW, Colors::YELLOW, Colors::YELLOW},
		{Colors::YELLOW, Colors::YELLOW, Colors::YELLOW}, //back
		{Colors::YELLOW, Colors::YELLOW, Colors::YELLOW}
	},

	{
		{Colors::GREEN, Colors::GREEN, Colors::GREEN},
		{Colors::GREEN, Colors::GREEN, Colors::GREEN}, //up
		{Colors::GREEN, Colors::GREEN, Colors::GREEN}
	},

	{
		{Colors::BLUE, Colors::BLUE, Colors::BLUE},
		{Colors::BLUE, Colors::BLUE, Colors::BLUE}, //down
		{Colors::BLUE, Colors::BLUE, Colors::BLUE}
	},

	{
		{Colors::ORANGE, Colors::ORANGE, Colors::ORANGE},
		{Colors::ORANGE, Colors::ORANGE, Colors::ORANGE}, //left
		{Colors::ORANGE, Colors::ORANGE, Colors::ORANGE}
	},

	{
		{Colors::RED, Colors::RED, Colors::RED},
		{Colors::RED, Colors::RED, Colors::RED}, //right
		{Colors::RED, Colors::RED, Colors::RED}
	}
};

class Cube
{
public:
	void rotateFace(Colors(&face)[3][3], bool clockwise);
	State cube_state;
	vector<string> solve_vector;

public: 
	Cube();
	Cube(const State& newState);

	void Generate_Random_State();

	void setState(const State& newState);
	State get_state();
	vector<string> get_Svector();

	void R();
	void _R();
	void L();
	void _L();
	void F();
	void _F();
	void B();
	void _B();
	void U();
	void _U();
	void D();
	void _D();
};

