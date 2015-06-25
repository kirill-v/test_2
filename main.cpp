#include <iostream>
#include <memory>
#include <string>

#include "basecounter.h"
#include "checksumcounter.h"
#include "wordcounter.h"

enum Mode {Help, Calculator, Counter};

void print_help()
{
    std::cout << "Usage (arguments order is important):\n";
    std::cout << "Count entries of word WORD in file FILE:\n";
    std::cout << "\ttest -f FILE -m words -v WORD\n";
    std::cout << "Calculate checksum of file FILE:\n";
    std::cout << "\ttest -f FILE -m checksum\n";
    std::cout << "Print this help and exit:\n";
    std::cout << "\ttest -h\n";
}

bool parse_command_line(int argc, char** argv, std::string& filename,
                        std::string& target_word, Mode& mode)
{
    bool success = false;
    if (argc == 2)
    {
        if (std::string("-h").compare(argv[1]) == 0)
        {
            success = true;
            mode = Mode::Help;
        }
    }
    else if(argc == 5)
    {
        if ((std::string("-f").compare(argv[1]) == 0) &&
            (std::string("-m").compare(argv[3]) == 0) &&
            (std::string("checksum").compare(argv[4]) == 0))
        {
            success = true;
            mode = Mode::Calculator;
            filename = argv[2];
        }
    }
    else if(argc == 7)
    {
        if ((std::string("-f").compare(argv[1]) == 0) &&
            (std::string("-m").compare(argv[3]) == 0) &&
            (std::string("words").compare(argv[4]) == 0) &&
            (std::string("-v").compare(argv[5]) == 0))
        {
            success = true;
            mode = Mode::Counter;
            filename = argv[2];
            target_word = argv[6];
        }
    }
    if (!success)
    {
        std::cout << "Error: wrong command line format\n";
        print_help();
    }
    return success;
}

int main(int argc, char** argv)
{
    std::string filename, target_word;
    Mode mode;
    if (!parse_command_line(argc, argv, filename, target_word, mode))
    {
        return -1;
    }
    if (mode == Mode::Help)
    {
        print_help();
        return 0;
    }
    std::shared_ptr<counter::BaseCounter> processor;
    switch (mode)
    {
    case Mode::Calculator:
        processor.reset(new counter::ChecksumCounter());
        break;
    case Mode::Counter:
        processor.reset(new counter::WordCounter(target_word));
        break;
    default:
        std::cout << "Error: unsupported mode\n";
        return -1;
    }

    std::cout << "Processing file: " << filename << std::endl;
    if (!processor->Process(filename))
    {
        std::cout << "Error occured. Exiting\n";
        return -1;
    }
    processor->PrintAnswer();
    return 0;
}

