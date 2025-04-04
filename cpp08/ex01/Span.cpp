# include "Span.hpp"

Span::Span(size_t N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _V(other._V) {} 

Span::~Span() {}

void    Span::addNumber(int n)
{
    if (_V.size() >= _N)
        throw Span::SpanFullException();
    _V.push_back(n);
}

int   Span::shortestSpan()
{
    if (_V.size() < 2)
        throw Span::SpanCanNotBeFound();
    
    std::vector<int> sortedV(_V);
    std::sort(sortedV.begin(), sortedV.end());
    
    int shortest = std::abs(sortedV[1] - sortedV[0]);
    for (size_t i = 1; i < sortedV.size() - 1; ++i)
    {
        int diff = std::abs(sortedV[i + 1] - sortedV[i]);
        if (diff < shortest)
            shortest = diff;
    }
    return (shortest);
}

int   Span::longestSpan()
{
    if (_V.size() < 2)
        throw Span::SpanCanNotBeFound();
    
    std::vector<int> sortedV(_V);
    std::sort(sortedV.begin(), sortedV.end());
    return (sortedV.back() - sortedV.front());
}

const char* Span::SpanFullException::what() const throw() 
{
    return  "Span is full, can't add more numbers.";
}

const char* Span::SpanCanNotBeFound::what() const throw()
{
    return "No span can be found.";
}

const char* Span::SpanRangeTooLarge::what() const throw()
{
    return "Range too large.";
}

Span&   Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_V = other._V;
    }
    return *this;
}