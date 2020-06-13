#include "cube_logic.h"

void Cube::rotateFace(Colors(&face)[3][3], bool clockwise)
{
	Colors buffer[3][3];

	if (clockwise)
	{
		for (int i = 0; i < 9; i++)
		{
			buffer[i / 3][i % 3] = face[i % 3][2 - i / 3];
		}
	}

	else
	{
		for (int i = 0; i < 9; i++)
		{
			buffer[i % 3][i / 3] = face[2 - i / 3][i % 3];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		face[i / 3][i % 3] = buffer[i / 3][i % 3];
	}
}

Cube::Cube()
{
	setState(defaultState);
}

Cube::Cube(const State& newState) 
{
	setState(newState);
}

State Cube::get_state()
{
	return cube_state;
}

vector<string> Cube::get_Svector()
{
	return solve_vector;
}

void Cube::Generate_Random_State()
{
	
	for (int i = 0; i < 50; i++)
	{
		int act = rand() % 12;

		if (act == 0)
		{
			F();

			solve_vector.push_back("F");
		}
		else if (act == 1)
		{
			_F();

			solve_vector.push_back("N");
		}
		else if (act == 2)
		{
			B();

			solve_vector.push_back("B");
		}
		else if (act == 3)
		{
			_B();

			solve_vector.push_back("M");
		}
		else if (act == 4)
		{
			U();

			solve_vector.push_back("U");
		}
		else if (act == 5)
		{
			_U();

			solve_vector.push_back("Z");
		}
		else if (act == 6)
		{
			D();

			solve_vector.push_back("D");
		}
		else if (act == 7)
		{
			_D();

			solve_vector.push_back("X");
		}
		else if (act == 8)
		{
			R();

			solve_vector.push_back("R");
		}
		else if (act == 9)
		{
			_R();

			solve_vector.push_back("V");
		}
		else if (act == 10)
		{
			L();

			solve_vector.push_back("L");
		}
		else if (act == 11)
		{
			_L();

			solve_vector.push_back("C");
		}
	}
}

void Cube::setState(const State& newState)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cube_state.Front[i][j] = newState.Front[i][j];
			cube_state.Back[i][j] = newState.Back[i][j];
			cube_state.Up[i][j] = newState.Up[i][j];
			cube_state.Down[i][j] = newState.Down[i][j];
			cube_state.Left[i][j] = newState.Left[i][j];
			cube_state.Right[i][j] = newState.Right[i][j];
		}
}

void Cube::F()
{
	State buffer;
	
	rotateFace(cube_state.Front, false);

	for (int i = 0; i < 3; i++)
	{
		buffer.Up[2][i] = cube_state.Left[2 - i][2];
		buffer.Left[i][2] = cube_state.Down[0][i];
		buffer.Down[0][i] = cube_state.Right[2 - i][0];
		buffer.Right[i][0] = cube_state.Up[2][i];
	}

	for (int i = 0; i < 3; i++)
	{
		cube_state.Up[2][i] = buffer.Up[2][i];
		cube_state.Down[0][i] = buffer.Down[0][i];
		cube_state.Left[i][2] = buffer.Left[i][2];
		cube_state.Right[i][0] = buffer.Right[i][0];
	}
}

void Cube::_F()
{
	State buffer;

	rotateFace(cube_state.Front, true);

	for (int i = 0; i < 3; i++)
	{
		buffer.Up[2][i] = cube_state.Right[i][0];
		buffer.Left[i][2] = cube_state.Up[2][2 - i];
		buffer.Down[0][i] = cube_state.Left[i][2];
		buffer.Right[i][0] = cube_state.Down[0][2 - i];
	}

	for (int i = 0; i < 3; i++)
	{
		cube_state.Up[2][i] = buffer.Up[2][i];
		cube_state.Down[0][i] = buffer.Down[0][i];
		cube_state.Left[i][2] = buffer.Left[i][2];
		cube_state.Right[i][0] = buffer.Right[i][0];
	}
}

void Cube::B()
{
	State buffer;

	rotateFace(cube_state.Back, false);
	
	for (int i = 0; i < 3; i++)
	{
		buffer.Up[0][i] = cube_state.Right[i][2];
		buffer.Left[i][0] = cube_state.Up[0][2 - i];
		buffer.Down[2][i] = cube_state.Left[i][0];
		buffer.Right[i][2] = cube_state.Down[2][2 - i];
	}

	for (int i = 0; i < 3; i++)
	{
		cube_state.Up[0][i] = buffer.Up[0][i];
		cube_state.Down[2][i] = buffer.Down[2][i];
		cube_state.Left[i][0] = buffer.Left[i][0];
		cube_state.Right[i][2] = buffer.Right[i][2];
	}
}

void Cube::_B()
{
	State buffer;

	rotateFace(cube_state.Back, true);

	for (int i = 0; i < 3; i++)
	{
		buffer.Up[0][i] = cube_state.Left[2 - i][0];
		buffer.Left[i][0] = cube_state.Down[2][i];
		buffer.Down[2][i] = cube_state.Right[2 - i][2];
		buffer.Right[i][2] = cube_state.Up[0][i];
	}

	for (int i = 0; i < 3; i++)
	{
		cube_state.Up[0][i] = buffer.Up[0][i];
		cube_state.Down[2][i] = buffer.Down[2][i];
		cube_state.Left[i][0] = buffer.Left[i][0];
		cube_state.Right[i][2] = buffer.Right[i][2];
	}
}

void Cube::U()
{
	State buffer;

	rotateFace(cube_state.Up, false);

	for (int i = 0; i < 3; i++)
	{
		buffer.Front[0][i] = cube_state.Right[0][i];
		buffer.Right[0][i] = cube_state.Back[0][i];
		buffer.Back[0][i] = cube_state.Left[0][i];
		buffer.Left[0][i] = cube_state.Front[0][i];
	}

	for (int i = 0; i < 3; i++)
	{
		cube_state.Front[0][i] = buffer.Front[0][i];
		cube_state.Right[0][i] = buffer.Right[0][i];
		cube_state.Back[0][i] = buffer.Back[0][i];
		cube_state.Left[0][i] = buffer.Left[0][i];
	}
}

void Cube::_U()
{
	State buffer;

	rotateFace(cube_state.Up, true);

	for (int i = 0; i < 3; i++)
	{
		buffer.Front[0][i] = cube_state.Left[0][i];
		buffer.Right[0][i] = cube_state.Front[0][i];
		buffer.Back[0][i] = cube_state.Right[0][i];
		buffer.Left[0][i] = cube_state.Back[0][i];
	}

	for (int i = 0; i < 3; i++)
	{
		cube_state.Front[0][i] = buffer.Front[0][i];
		cube_state.Right[0][i] = buffer.Right[0][i];
		cube_state.Back[0][i] = buffer.Back[0][i];
		cube_state.Left[0][i] = buffer.Left[0][i];
	}
}

void Cube::D()
{
	State buffer;

	rotateFace(cube_state.Down, false);

	for (int i = 0; i < 3; i++)
	{
		buffer.Front[2][i] = cube_state.Left[2][i];
		buffer.Right[2][i] = cube_state.Front[2][i];
		buffer.Back[2][i] = cube_state.Right[2][i];
		buffer.Left[2][i] = cube_state.Back[2][i];
	}
	for (int i = 0; i < 3; i++)
	{
		cube_state.Front[2][i] = buffer.Front[2][i];
		cube_state.Right[2][i] = buffer.Right[2][i];
		cube_state.Back[2][i] = buffer.Back[2][i];
		cube_state.Left[2][i] = buffer.Left[2][i];
	}
}

void Cube::_D()
{
	State buffer;

	rotateFace(cube_state.Down, true);

	for (int i = 0; i < 3; i++)
	{
		buffer.Front[2][i] = cube_state.Right[2][i];
		buffer.Right[2][i] = cube_state.Back[2][i];
		buffer.Back[2][i] = cube_state.Left[2][i];
		buffer.Left[2][i] = cube_state.Front[2][i];
	}
	for (int i = 0; i < 3; i++)
	{
		cube_state.Front[2][i] = buffer.Front[2][i];
		cube_state.Right[2][i] = buffer.Right[2][i];
		cube_state.Back[2][i] = buffer.Back[2][i];
		cube_state.Left[2][i] = buffer.Left[2][i];
	}
}

void Cube::_R()
{
	State buffer;

	rotateFace(cube_state.Right, true);

	for (int i = 0; i < 3; i++)
	{
		buffer.Up[i][2] = cube_state.Back[2 - i][0];
		buffer.Back[i][0] = cube_state.Down[2 - i][2];
		buffer.Down[i][2] = cube_state.Front[i][2];
		buffer.Front[i][2] = cube_state.Up[i][2];
	}
	for (int i = 0; i < 3; i++)
	{
		cube_state.Up[i][2] = buffer.Up[i][2];
		cube_state.Down[i][2] = buffer.Down[i][2];
		cube_state.Front[i][2] = buffer.Front[i][2];
		cube_state.Back[i][0] = buffer.Back[i][0];
	}
}

void Cube::R()
{
	State buffer;

	rotateFace(cube_state.Right, false);

	for (int i = 0; i < 3; i++)
	{
		buffer.Up[i][2] = cube_state.Front[i][2];
		buffer.Back[i][0] = cube_state.Up[2 - i][2];
		buffer.Down[i][2] = cube_state.Back[2 - i][0];
		buffer.Front[i][2] = cube_state.Down[i][2];
	}
	for (int i = 0; i < 3; i++)
	{
		cube_state.Up[i][2] = buffer.Up[i][2];
		cube_state.Down[i][2] = buffer.Down[i][2];
		cube_state.Front[i][2] = buffer.Front[i][2];
		cube_state.Back[i][0] = buffer.Back[i][0];
	}
}

void Cube::_L()
{
	State buffer;

	rotateFace(cube_state.Left, true);

	for (int i = 0; i < 3; i++)
	{
		buffer.Up[i][0] = cube_state.Front[i][0];
		buffer.Back[i][2] = cube_state.Up[2 - i][0];
		buffer.Down[i][0] = cube_state.Back[2 - i][2];
		buffer.Front[i][0] = cube_state.Down[i][0];
	}
	for (int i = 0; i < 3; i++)
	{
		cube_state.Up[i][0] = buffer.Up[i][0];
		cube_state.Down[i][0] = buffer.Down[i][0];
		cube_state.Front[i][0] = buffer.Front[i][0];
		cube_state.Back[i][2] = buffer.Back[i][2];
	}
}

void Cube::L()
{
	State buffer;

	rotateFace(cube_state.Left, false);

	for (int i = 0; i < 3; i++)
	{
		buffer.Up[i][0] = cube_state.Back[2 - i][2];
		buffer.Back[i][2] = cube_state.Down[2 - i][0];
		buffer.Down[i][0] = cube_state.Front[i][0];
		buffer.Front[i][0] = cube_state.Up[i][0];
	}
	for (int i = 0; i < 3; i++)
	{
		cube_state.Up[i][0] = buffer.Up[i][0];
		cube_state.Down[i][0] = buffer.Down[i][0];
		cube_state.Front[i][0] = buffer.Front[i][0];
		cube_state.Back[i][2] = buffer.Back[i][2];
	}
}