#include <iostream>
#include <string>
#include "cxxopts.hpp"

int main(int argc, char** argv)
{
    cxxopts::Options options("test", "A brief description");

    options.add_options()
        ("d,download", "Param filepath", cxxopts::value<std::string>())
        ("e,execute",  "Param execute",  cxxopts::value<bool>()->default_value("false"))
        ("r,repl",     "Param repl",     cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage")
        ;

    try 
    {
        auto result = options.parse(argc, argv);
        if (result.count("help"))
        {
            std::cout << options.help() << std::endl;
            exit(0);
        }

        auto str = result["download"].as<std::string>();
        std::cout << "Filepath: " << str << '\n';

        auto execute = result["execute"].as<bool>();
        std::cout << "Execute: " << execute << '\n';

        auto repl = result["repl"].as<bool>();
        std::cout << "Repl: " << repl << '\n';
    }
    catch (cxxopts::OptionException err)
    {
        std::cout << err.what();
    }

    return 0;
}