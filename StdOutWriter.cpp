#include <iostream>
#include "StdOutWriter.h"

void StdOutWriter::write(std::string &line) {
    std::cout << line << std::endl;
}

std::shared_ptr<StdOutWriter> StdOutWriter::create() {
    std::shared_ptr<StdOutWriter> self(new StdOutWriter);
    return self;
}