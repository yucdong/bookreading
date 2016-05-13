#ifndef _STRVEC_H_
#define _STRVEC_H_

#include <string>
#include <utility>
#include <memory>

class StrVec {
public:
    StrVec() 
      : elements(nullptr), 
        first_free(nullptr),
        cap(nullptr)
        { }

    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec(StrVec &&) noexcept;
    StrVec& operator=(StrVec &&) noexcept;
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
private:
    std::allocator<std::string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void reallocate();

    // Elements
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

#endif
