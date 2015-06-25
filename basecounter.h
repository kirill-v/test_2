#ifndef BASECOUNTER_H
#define BASECOUNTER_H

#include <cstdint>
#include <iostream>
#include <string>

namespace counter
{
class BaseCounter
{
public:
    typedef uint32_t CounterType;

    BaseCounter(): _counter(0) {}

    virtual ~BaseCounter() {}

    virtual bool Process(const std::string& filename) = 0;

    CounterType GetCounter() const {  return _counter; }

    virtual void PrintAnswer() const = 0;

    void Reset() { _counter = 0; }

protected:
    bool check_filename(const std::string& filename) const;

    CounterType _counter;
};
} // namespace counter
#endif // BASECOUNTER_H
