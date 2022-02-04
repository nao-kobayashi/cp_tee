#ifndef CP_TEE_FILEWRITER_H
#define CP_TEE_FILEWRITER_H


#include <string>
#include <fstream>
#include "WriterBase.h"

class FileWriter: public WriterBase {
public:
    virtual ~FileWriter() override;

    void write(const std::string &line) override;

    static std::shared_ptr<FileWriter> create(
        const std::string file_path,
        const bool append,
        const bool put_now);

private:
    FileWriter();
    explicit FileWriter(const std::string fp, const bool app, const bool now);

    std::string getDatetimeStr() const;

    std::ofstream file_stream;
    const std::string file_path;
    const bool append;
    const bool put_now;
};


#endif