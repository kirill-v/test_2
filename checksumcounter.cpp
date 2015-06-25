#include "checksumcounter.h"

#include <fstream>
namespace  counter
{
bool ChecksumCounter::Process(const std::string& filename)
{
    if (!check_filename(filename))
    {
        return false;
    }
    std::fstream in_stream(filename, std::ios_base::binary | std::ios_base::in);
    if (!in_stream)
    {
        std::cout << "Error occurred while opening file: " << filename << std::endl;
        return false;
    }

    CounterType counter = 0, buffer;
    while(true)
    {
        // fill buffer with 0 if file_size % 4 != 0
        buffer = 0x0;
        in_stream.read((char*)&buffer, sizeof(buffer));
        if (in_stream.eof())
        {
            if (in_stream.gcount() != 0)
            {
                counter += buffer;
            }
            break;
        }
        counter += buffer;
        if (!in_stream.good())
        {
            std::cout << "Error occurred while reading from file: " << filename << std::endl;
            return false;
        }
    }
    _counter += buffer;
    return true;
}

void ChecksumCounter::PrintAnswer() const
{
    std::cout << "ChecksumCounter: current sum: " << _counter << std::endl;
}
} // namespace  counter
