
#ifndef CP_TEE_STDOUTWRITER_H
#define CP_TEE_STDOUTWRITER_H


#include "WriterBase.h"

class StdOutWriter: public WriterBase {
public:
    void write(std::string &line) override;
    static std::shared_ptr<StdOutWriter> create();
};


#endif
