#ifndef CP_TEE_WRITERBASE_H
#define CP_TEE_WRITERBASE_H

#include <string>

class WriterBase {
public:
    virtual ~WriterBase() = 0;
    virtual void write(const std::string &line) = 0;
};


#endif