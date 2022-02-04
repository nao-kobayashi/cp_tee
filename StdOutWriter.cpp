#include <iostream>
#include "StdOutWriter.h"

StdOutWriter::StdOutWriter() {}
StdOutWriter::~StdOutWriter() {}

void StdOutWriter::write(const std::string &line) {
    std::cout << line << std::endl;
}

std::shared_ptr<StdOutWriter> StdOutWriter::create() {
    std::shared_ptr<StdOutWriter> self(new StdOutWriter);
    return self;
}