#ifndef CP_TEE_FILEWRITER_H
#define CP_TEE_FILEWRITER_H


#include <string>
#include <fstream>
#include "WriterBase.h"

class FileWriter: public WriterBase {
public:
    FileWriter(std::string fp, bool app, bool now);
    ~FileWriter();
    void write(std::string &line) override;
    static std::shared_ptr<FileWriter> create(std::string file_path, bool append, bool put_now);

private:
    std::string getDatetimeStr();

    std::ofstream file_stream;
    std::string file_path;
    bool append;
    bool put_now;
};


#endif