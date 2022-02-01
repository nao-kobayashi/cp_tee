#include <iostream>
#include <iomanip>
#include <sstream>
#include "FileWriter.h"

FileWriter::FileWriter(std::string fp, bool app, bool now)
    :file_path(fp), append(app), put_now(now), file_stream() {

    if (append) {
        file_stream.open(file_path, std::ios_base::out | std::ios_base::app);
    } else {
        file_stream.open(file_path, std::ios_base::out | std::ios_base::trunc);
    }
}

FileWriter::~FileWriter() {
    file_stream.close();
}

void FileWriter::write(std::string &line) {
    if (put_now) {
        file_stream << getDatetimeStr() << " " << line << std::endl;
    } else {
        file_stream << line << std::endl;
    }
}

std::shared_ptr<FileWriter> FileWriter::create(std::string file_path, bool append, bool put_now) {
    std::shared_ptr<FileWriter> self(new FileWriter(file_path, append, put_now));
    return self;
}

std::string FileWriter::getDatetimeStr() {
    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);

    std::stringstream s;

    s << localTime->tm_year + 1900 << "/";
    // std::setw(),std::setfill()で0詰め
    s << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1 << "/";
    s << std::setw(2) << std::setfill('0') << localTime->tm_mday;
    s << " ";
    s << std::setw(2) << std::setfill('0') << localTime->tm_hour << ":";
    s << std::setw(2) << std::setfill('0') << localTime->tm_min << ":";
    s << std::setw(2) << std::setfill('0') << localTime->tm_sec;
    
    return s.str();
}