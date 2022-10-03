#ifndef SRC_FILES_HPP
#define SRC_FILES_HPP

#include <vector>
#include <string>

namespace files {
    class Files {
        public:
            static inline std::vector<std::string> verses;

            static void parseVersesTXT();
    };
}

#endif