
#include "point.hpp"
#include "line.hpp"

#include <cassert>
#include <sstream>

void test_point()
{
    // Test operator==
    {
        const point p1{1, 2};
        const point p2 = p1;
        const point p3{3, 4};

        assert(p1 == p2);
        assert(!(p1 == p3));
    }

    // Test operator!=
    {
        const point p1{1, 2};
        const point p2 = {3, 4};
        const point p3 = p1;

        assert(p1 != p2);
        assert(!(p1 != p3));
    }

    // Test operator+
    {
        const point p1{1, 2};
        const point p2{3, 4};
        const point p3{4, 6};

        assert(p1 + p2 == p3);
    }

    // Test operator-
    {
        const point p1{3, 4};
        const point p2{1, 2};
        const point p3{2, 2};

        assert(p1 - p2 == p3);
    }

    // Test operator+=
    {
        point p1{1, 2};
        const point p2{3, 4};
        const point result{4, 6};

        p1 += p2;

        assert(p1 == result);
    }

    // Test operator-=
    {
        point p1{3, 4};
        const point p2{1, 2};
        const point result{2, 2};

        p1 -= p2;

        assert(p1 == result);
    }

    // Test output streaming
    {
        std::ostringstream ss;
        ss << point{3, 4} << '\n';
        assert(ss.str() == "(3, 4)\n");
    }
}

void test_line()
{
    // line can be default-constructed
    {
        const line l{};
        const point p{};
        assert(l.start_ == p);
        assert(l.end_ == p);
    }

    // line can be constructed from two points
    {
        const point p1{1, 2};
        const point p2{3, 4};

        const line l{p1, p2};

        assert(l.start_ == p1);
        assert(l.end_ == p2);
    }
}

int main()
{
    test_point();
    test_line();
}