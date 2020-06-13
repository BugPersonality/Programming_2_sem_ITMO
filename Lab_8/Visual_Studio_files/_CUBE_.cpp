#include <iostream>
#include"Cube_menager.h"

int main()
{

	string command;

	Cube_menager object(1);

	object.cube.Generate_Random_State();

	while (command != "stop")
	{
		cout << "Enter the command: " << endl;
		cin >> command;

		if (command == "save")
		{
			object.save_state("C:\\Users\\danil\\Desktop\\u_c\\cube_state.txt");
		}
		else if (command == "save_solve")
		{
			object.save_solve("C:\\Users\\danil\\Desktop\\u_c\\solve.txt");
		}
		else if (command == "save_i_s")
		{
			object.save_invert_solve("C:\\Users\\danil\\Desktop\\u_c\\invert_solve.txt");
		}
		else if (command == "left")
		{
			object.cube.L();

			cout << "successfully turned side " << endl;
		}
		else if (command == "right")
		{
			object.cube.R();

			cout << "successfully turned side " << endl;
		}
		else if (command == "up")
		{
			object.cube.U();

			cout << "successfully turned side " << endl;
		}
		else if (command == "down")
		{
			object.cube.D();

			cout << "successfully turned side " << endl;
		}
		else if (command == "front")
		{
			object.cube.F();

			cout << "successfully turned side " << endl;
		}
		else if (command == "back")
		{
			object.cube.B();

			cout << "successfully turned side " << endl;
		}
		else if (command == "left'")
		{
			object.cube._L();

			cout << "successfully turned side " << endl;
		}
		else if (command == "right'")
		{
			object.cube._R();

			cout << "successfully turned side " << endl;
		}
		else if (command == "up'")
		{
			object.cube._U();

			cout << "successfully turned side " << endl;
		}
		else if (command == "down'")
		{
			object.cube._D();

			cout << "successfully turned side " << endl;
		}
		else if (command == "front'")
		{
			object.cube._F();

			cout << "successfully turned side " << endl;
		}
		else if (command == "back'")
		{
			object.cube._B();

			cout << "successfully turned side " << endl;
		}
		else if (command == "print_state")
		{
			object.cout_state();

			cout << "successfully turned side " << endl;
		}
		else if (command == "solve_cube")
		{
			object.solve_cube();
		}

		cout << endl;
	}

	return 0;
}

