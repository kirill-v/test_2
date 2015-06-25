#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include "basecounter.h"

namespace counter
{
class WordCounter: public BaseCounter
{
public:
    WordCounter(const std::string& target_string);

    virtual bool Process(const std::string &filename);

    virtual void PrintAnswer() const;

private:
    std::string _target;
};
} // namespace counter
#endif // WORDCOUNTER_H
