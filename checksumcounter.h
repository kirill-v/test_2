#ifndef CHECKSUMCOUNTER_H
#define CHECKSUMCOUNTER_H

#include "basecounter.h"

namespace counter
{
class ChecksumCounter: public BaseCounter
{
public:
    virtual bool Process(const std::string& filename);

    virtual void PrintAnswer() const;
};
} // namespace counter
#endif // CHECKSUMCOUNTER_H
