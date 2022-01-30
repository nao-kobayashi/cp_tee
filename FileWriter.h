#ifndef CP_TEE_FILEWRITER_H
#define CP_TEE_FILEWRITER_H


#include <string>
#include "WriterBase.h"

class FileWriter: public WriterBase {
public:
    void write(std::string &line) override;
    static std::shared_ptr<FileWriter> create(std::string file_path, bool append, bool put_now);

private:
    std::string file_path;
    bool append;
    bool put_now;
};


#endif