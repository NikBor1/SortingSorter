#include <iostream>
#include <vector>

void bubble(std::vector<int>& sorting);





int main()
{
    std::vector <std::vector <std::vector <int>>> controlGroup(10, std::vector<std::vector <int>> (4, std::vector <int> (0)));
    /*
    1-10 - ten experimental sorts

    1 - rand
    2 - sorted
    3 - sorted back
    4 - 90% sorted
    */

    for(int i = 0; i < 10000; i ++)
    {
        int x = rand() % 1000;

        for(int j = 0; j < 4; j ++)
        {
            controlGroup[j][0].push_back(x);
            controlGroup[j][1].push_back(i);
            controlGroup[j][2].push_back(i);

            if(i % 1000 == 0)
                controlGroup[j][3].push_back(x);
            else
                controlGroup[j][3].push_back(i);
        }

    }


    for(int i = 0; i < 1000000; i ++)
    {
        int x = rand() % 10000;

        for(int j = 4; j < 10; j ++)
        {
            controlGroup[j][0].push_back(x);
            controlGroup[j][1].push_back(i);
            controlGroup[j][2].push_back(10000 - i);

            if(i % 100000 == 0)
                controlGroup[j][3].push_back(x);
            else
                controlGroup[j][3].push_back(i);
        }

    }

    return 0;
}

void bubble(std::vector<int>& sorting)
{
    for(int i = 1; i < (*sorting).size(); i ++)
    {
        for(int j = i; j < (*sorting).size(); i ++)
        {
            if((*sorting)[i] < (*sorting)[i - 1])
                std::swap((*sorting)[i], (*sorting)[i - 1]);
        }
    }
}
