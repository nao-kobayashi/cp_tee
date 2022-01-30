#include <iostream>
#include <vector>
#include <string>
#include "WriterBase.h"
#include "StdOutWriter.h"
#include "FileWriter.h"

bool iter_any(std::vector<std::string> &iter, std::function<bool(std::string)> pred) {
    return std::any_of(iter.begin(), iter.end(), pred);
}

int main(int argc, char *argv[]) {
    std::vector<std::string> params(argv + 1, argv + argc);

    bool append = iter_any(params, [](std::string x) { return x == "-a" || x == "-A"; });
    bool put_now = iter_any(params, [](std::string x) { return x == "-d" || x == "-D"; });

    std::vector<std::string> files;
    std::copy_if(
            params.begin(),
            params.end(),
            std::back_inserter(files),
            [](std::string &x) { return x[0] != '-';});

    std::vector<std::shared_ptr<WriterBase>> writers;
    writers.push_back(StdOutWriter::create());
    for (auto file_path : files) {
        writers.push_back(FileWriter::create(file_path, append, put_now));
    }

    std::string line;
    while (true) {
        std::cin >> line;
        if (std::cin.eof())
            break;

        for (auto w : writers) {
            w->write(line);
        }
    }

    return 0;
}
