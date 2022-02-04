
#ifndef CP_TEE_STDOUTWRITER_H
#define CP_TEE_STDOUTWRITER_H


#include "WriterBase.h"

class StdOutWriter: public WriterBase {
public:
    virtual ~StdOutWriter() override;
    void write(const std::string &line) override;
    static std::shared_ptr<StdOutWriter> create();

private:
    StdOutWriter();
};


#endif
