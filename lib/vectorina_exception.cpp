#include "vectorina.h"

vectorina_exception::vectorina_exception(const char *error_text, int32_t line)
{
    this->msg = strdup(error_text);
    this->line = line;
}

vectorina_exception::vectorina_exception(const vectorina_exception &obj)
{
    this->msg = strdup(obj.msg);
    this->line = line;
}

vectorina_exception::~vectorina_exception()
{
    delete this->msg;
}

const char *vectorina_exception::what()
{
    static char exception_string[4 KiB];
    sprintf(exception_string, "%s -- LINE: %d", this->msg, this->line);
    return exception_string;
}
