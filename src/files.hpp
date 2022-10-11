#ifndef SRC_FILES_HPP
#define SRC_FILES_HPP

#include <vector>
#include <string>

namespace files {
    class Files {
        public:
            static inline std::vector<std::string> verses;
            static inline std::vector<std::string> dreams;
            static inline std::vector<std::string> attentionGrabbers;
            static inline std::vector<std::string> complements;
            static inline std::vector<std::string> details;
            static inline std::vector<std::string> insults;
            static inline std::vector<std::string> words;

            static void parseVersesTXT();
            static void parseBetterDreams();
            static void parseLoveLetterFiles();
            static void parseInsults();
            static void parseWords();
    };
}

#endif