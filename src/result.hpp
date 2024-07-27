
#ifndef RESULT_HPP
#define RESULT_HPP

#include <string>

struct Result
{
  public:
    static Result error();

    static Result error(std::string message);

    static Result ok();

    bool isOk();

    bool isError();

    std::string getMessage();

  private:
    std::string message;
    bool resultOk;
};

#endif
