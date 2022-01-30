#ifndef CP_TEE_WRITERBASE_H
#define CP_TEE_WRITERBASE_H

#include <string>

class WriterBase {
public:
    virtual void write(std::string &line) = 0;
};


#endif