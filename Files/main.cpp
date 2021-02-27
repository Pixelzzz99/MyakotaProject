#include <iostream>
#include "Subword.hpp"
#include "TaskGenerator.hpp"
#include "UnOptimizedVersion.hpp"
#include "OptimizedVersion.hpp"
#include <fstream>
#include <ctime>

int test1()
{
    std::ofstream out1;
    int n = 10;

    out1.open("D:\\projects\\MyakotaProject\\Tables\\Table.csv");
    if (out1.is_open())
    {
        while (n <= 300)
        {
            TaskGenerator *task = new TaskGenerator(n, n);
            Subword *test1 = new Subword(new UnOptimizedVersion(task));
            Subword *test2 = new Subword(new OptimizedVersion(task));

            unsigned int start_time_test1 = clock();
            std::string result1 = test1->DoAlgorithm();
            unsigned int end_time_test1 = clock();
            double time1 = (double)(end_time_test1 - start_time_test1) / CLOCKS_PER_SEC;

            unsigned int start_time_test2 = clock();
            std::string result2 = test2->DoAlgorithm();
            unsigned int end_time_test2 = clock();
            double time2 = (double)(end_time_test2 - start_time_test2) / CLOCKS_PER_SEC;

            std::string equalsResult = "false";
            if (result1.size() == result2.size())
            {
                equalsResult = "true";
            }
            std::cout << n << "\t" << result1 << "\t" << time1 << "\t" << result2 << "\t" << time2 << "\t" << time1 / test1->get_index() << "\t" << time2 / test2->get_index() << "\t" << equalsResult << std::endl;
            out1 << n << ";" << time1 << ";" << time2 << ";" << time1 / test1->get_index() << ";" << time2 / test2->get_index() << ";" << equalsResult << std::endl;
            delete test1;
            delete test2;
            delete task;
            n += 30;
        }
    }
    std::cout << "TestFinished" << std::endl;
    return 1;
}

int test2()
{
    std::ofstream out1;
    int n = 100;

    out1.open("D:\\projects\\MyakotaProject\\Tables\\Table1.csv");
    if (out1.is_open())
    {
        while (n <= 20000)
        {
            TaskGenerator *task = new TaskGenerator(n, n);
            Subword *test2 = new Subword(new OptimizedVersion(task));

            unsigned int start_time_test2 = clock();
            std::string result2 = test2->DoAlgorithm();
            unsigned int end_time_test2 = clock();
            double time2 = (double)(end_time_test2 - start_time_test2) / CLOCKS_PER_SEC;

            std::cout << n << "\t" << result2 << "\t" << time2 << "\t" << time2 / test2->get_index() << "\t" << std::endl;
            out1 << n << ";" << time2 << ";" << time2 / test2->get_index() << ";" << std::endl;
            delete test2;
            delete task;
            n += 100;
        }
    }
    std::cout << "TestFinished" << std::endl;
    return 1;
}

int main()
{
    test2();
    system("pause>nul");

    return 0;
}