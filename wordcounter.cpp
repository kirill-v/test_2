#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "wordcounter.h"

namespace counter
{
WordCounter::WordCounter(const std::string& target_string)
    : BaseCounter(), _target(target_string)
{}

bool WordCounter::Process(const std::string& filename)
{
    if (!check_filename(filename))
    {
        return false;
    }
    std::ifstream in_stream(filename);
    if (!in_stream)
    {
        std::cout << "Error occurred while opening file: " << filename << std::endl;
        return false;
    }

    CounterType counter = 0;
    const int chunk = 100;
    // buffer size has to be greater than size of target string
    const int buffer_size = chunk + _target.size();
    char buffer[buffer_size];
    // fill buffer with symbol that doesn't appear in target string
    std::fill(buffer, buffer + buffer_size, ' ');
    std::string line;
    line.resize(buffer_size);
    std::size_t position;
    // Beginning of the buffer contains end of the previous chunk
    while(in_stream.get(buffer + _target.size() - 1, chunk + 1, '\0'))
    {
        line = buffer;
        position = 0;
        while(true)
        {
            position = line.find(_target, position);
            if (position == std::string::npos)
            {
                break;
            }
            ++counter;
            position += _target.size();
        }
        // copy potential beginning of target string to analyze it next time
        memcpy(buffer, buffer + chunk, _target.size() - 1);

    }
    in_stream.close();
    _counter += counter;
    return true;
}

void WordCounter::PrintAnswer() const
{
    std::cout << "WordCounter: counter for word '" << _target << "': " << _counter << std::endl;
}
} // namespace counter
