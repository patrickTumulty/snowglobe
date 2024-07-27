
#include <result.hpp>

Result Result::error()
{
    return error("");
}

Result Result::error(std::string message)
{
    Result result;
    result.message = std::string(message);
    result.resultOk = false;
    return result;
}

Result Result::ok()
{
    Result result;
    result.message = "";
    result.resultOk = true;
    return result;
}

bool Result::isOk()
{
    return resultOk;
}

bool Result::isError()
{
    return !isOk();
}
