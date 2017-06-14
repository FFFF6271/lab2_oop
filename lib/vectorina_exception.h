#ifndef L2_OOP_VECTORINA_EXCEPTION_H
#define L2_OOP_VECTORINA_EXCEPTION_H

class vectorina_exception : std::exception
{
public:
    explicit vectorina_exception(const char *, int32_t);
    
    vectorina_exception(const vectorina_exception &obj);
    virtual ~vectorina_exception();
    
    const char *what();
private:
    char *msg;
    int32_t line;
};


class vectorina_out_of_range : public vectorina_exception
{
public:
    explicit vectorina_out_of_range(const char *error_text, int32_t line) :
        vectorina_exception(error_text, line)
    {}
};

class vectorina_wrong_dimension : public vectorina_exception
{
public:
    explicit vectorina_wrong_dimension(const char *error_text, int32_t line) :
        vectorina_exception(error_text, line)
    {}
};

class vectorina_division_by_zero : public vectorina_exception
{
public:
    explicit vectorina_division_by_zero(const char *error_text, int32_t line) :
    vectorina_exception(error_text, line)
    {}
};

#endif //L2_OOP_VECTORINA_EXCEPTION_H
