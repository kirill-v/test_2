#include "basecounter.h"
namespace counter
{
bool BaseCounter::check_filename(const std::string& filename) const
{
    if (filename.empty())
    {
        std::cout << "Error: filename is empty\n";
        return false;
    }
    return true;
}
} //namespace counter
