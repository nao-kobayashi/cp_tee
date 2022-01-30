#include <iostream>
#include "FileWriter.h"

void FileWriter::write(std::string &line) {
    std::cout << "file write:" << file_path << std::endl;
}

std::shared_ptr<FileWriter> FileWriter::create(std::string file_path, bool append, bool put_now) {
    std::shared_ptr<FileWriter> self(new FileWriter);
    self->file_path = file_path;
    self->append = append;
    self->put_now = put_now;
    return self;
}