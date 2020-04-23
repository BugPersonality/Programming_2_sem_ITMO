#include "header_1.h"
#include <iostream>
using namespace std;

int main()
{
    vector v_points;
    square sq_points;
    string command;

    cout << "enter vector dots\n";
    cin >> v_points.A.x >> v_points.A.y >> v_points.B.x >> v_points.B.y;
    cout << "enter square dots\n";
    cin >> sq_points.point_1.x >> sq_points.point_1.y >> sq_points.point_2.x >> sq_points.point_2.y;
    cin >> sq_points.point_3.x >> sq_points.point_3.y >> sq_points.point_4.x >> sq_points.point_4.y;
    cout << "Enter command\n";
    cin >> command;

    cout << "Square dots after transfer: " << endl;
    cout << sq_points.point_1.x << " " << sq_points.point_1.y << "\t" << sq_points.point_2.x << " " << sq_points.point_2.y << endl;
    cout << sq_points.point_3.x << " " << sq_points.point_3.y << "\t" << sq_points.point_4.x << " " << sq_points.point_4.y << "\n\n";

    if (command == "1")
    {
        vector_transfer_1(v_points, sq_points);
    }
    else
    {
        vector_transfer_2(&v_points, &sq_points);
    }

    cout << "Square dots after transfer:" << endl;
    cout << sq_points.point_1.x << " " << sq_points.point_1.y << "\t" << sq_points.point_2.x << " " << sq_points.point_2.y << endl;
    cout << sq_points.point_3.x << " " << sq_points.point_3.y << "\t" << sq_points.point_4.x << " " << sq_points.point_4.y;
    return 0;
}

