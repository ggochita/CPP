#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <stdexcept>
# include <vector>
# include <cstddef>

class Span
{
private:
    size_t              _N;
    std::vector<int>    _V;
public:
    Span(size_t N);
    Span(const Span& copy);
    ~Span();

    Span&   operator=(const Span& other);

    void    addNumber(int n);
    
    
    int   shortestSpan();
    int   longestSpan();
    
    class   SpanFullException : public std::exception {
        public:
        virtual const char* what() const throw();
    };

    class SpanCanNotBeFound : public std::exception {
        public:
        virtual const char* what() const throw();
    };
    
    class SpanRangeTooLarge : public std::exception {
        public:
        virtual const char* what() const throw();
    };
    
    template <typename Iterator>
    void    addRange(Iterator begin, Iterator end)
    {
        if (_V.size() + std::distance(begin, end) > _N)
            throw Span::SpanRangeTooLarge();
    
        _V.insert(_V.end(), begin, end);
    }

};

#endif
