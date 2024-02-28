#include "Span.hpp"
#include <list>

int	main(void) {

    std::cout << "Base test" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    std::cout << std::endl << "Copy constructor test" << std::endl;
    Span test(sp);
    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    std::cout << std::endl << "Range of iterators test" << std::endl;
    Span test3 = Span(100);

    test3.addNumber(sp.getList().begin(), sp.getList().end());
    test3.addNumber(150);
    test3.addNumber(300);
    test3.addNumber(500);
    test3.addNumber(sp.getList().begin(), sp.getList().end());
    std::list<int>::const_iterator it;
    for (it = test3.getList().begin(); it != test3.getList().end(); ++it)
        std::cout << *it << std::endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    std::cout << std::endl << "TooManyNumbers test" << std::endl;
    Span test4 = Span(2);

    test4.addNumber(150);
    test4.addNumber(300);
    try {
      test4.addNumber(500);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
 
    std::cout << std::endl << "TooFewNumbers test" << std::endl;
    Span test5 = Span(2);

    test5.addNumber(150);
    try {
        std::cout << test5.shortestSpan() << std::endl;
        std::cout << test5.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}