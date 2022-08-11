#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <vector>
#include <stdexcept>

#include "console.h"

class Logger {
public:
  void print(const std::string &message) {
    output.push_back(message);

    std::size_t console_height = console->height();
    console->clear();
    for(std::size_t i = 0; i < output.size() && i < console_height; i++) {
        console->moveCursor(0, i);

        int first_print_index = console_height > output.size() ? i : output.size() - console_height + i;
        console->print(output[first_print_index].c_str());
    }
    console->refresh();
  }

  static Logger &getInstance(tubs::ui::Console* console = nullptr) {
    static Logger logger(console);
    return logger;
  }

private:
    Logger(tubs::ui::Console* console) : console(console) {
        if (!console) {
            throw std::runtime_error("Logger needs to be called initallialy with an instane of tubs::ui::Console");
        }
    }

    std::vector<std::string> output;
    tubs::ui::Console* console;
};


#endif // __LOGGER_H__