#include "virtual_functions.h"
#include <vector>
#include <algorithm>

int main()
{
    vector<all*> array;
    string command;

    while (command != "stop")
    {
        cout << "Enter your command: " << endl;
        cin >> command;

        if (command == "add")
        {
            string name;

            cout << "Enter the name of the figure you want to add: " << endl;
            cin >> name;

            if (name == "hexagon")
            {
                array.push_back(new hexagon());
            }
            else if (name == "line")
            {
                array.push_back(new line_section());
            }
            array.back()->initFromDialog();
        }

        else if (command == "all_print")
        {
            for(auto &i : array)
            {
                i->print();
                cout << endl;
            }
        }

        else if (command == "all_area")
        {
            double sum = 0;
            for(auto &i : array)
            {
                sum += i->get_area();
            }

            cout << "all_area: " << sum << endl;
        }

        else if (command == "all_per")
        {
            double sum = 0;
            for(auto &i : array)
            {
                sum += i->get_perimeter();
            }

            cout << "all_perimeter: " << sum << endl;
        }

        else if (command == "center_mass")
        {
            vector_2D center(0, 0);
            double mass_sum = 0;

            for(auto &i : array)
            {
                center.x += i->get_position().x * i->get_mass();
                center.y += i->get_position().y * i->get_mass();
                mass_sum += i->get_mass();
            }

            center.x = center.x / mass_sum;
            center.y = center.y / mass_sum;

            cout << "X-center: " << center.x << " Y-center: " << center.y << endl;
        }

        else if (command == "all_mem")
        {
            uint64_t memory = 0;

            for(auto &i : array)
            {
                memory += i->get_size();
            }

            cout << "all_memory: " << memory << endl;
        }

        else if (command == "sort")
        {
            sort(array.begin(), array.end(), [](all* x, all* y) {return *x < *y;});
            std::cout << "Sorted." << std::endl;
        }
    }
}