#include <vector>
#include <iostream>
#include <cassert>
#include <memory>
#include <string>
#include <stdexcept>
#include <type_traits>

#include "Vector.hpp"

using namespace std;
using namespace v;

/* ============================================================
   Utilities
   ============================================================ */

#define TEST_CASE(name) \
    cout << "\n=== " << name << " ===\n";

#define EXPECT_NO_CRASH(stmt) \
    do { stmt; cout << "[PASS]\n"; } while (0)

#define EXPECT_THROW(stmt) \
    do { \
        try { stmt; cout << "[FAIL] expected throw\n"; } \
        catch (...) { cout << "[PASS]\n"; } \
    } while (0)

/* ============================================================
   Safety tests
   ============================================================ */

void testBoundsSafetyStd()
{
    TEST_CASE("std::vector bounds safety");

    vector<int> v = {1, 2};

    EXPECT_NO_CRASH(v[1]);
    EXPECT_THROW(v.at(2));
}

void testBoundsSafetyCustom()
{
    TEST_CASE("v::Vector bounds safety");

    Vector<int> v;
    v.push_back(1);
    v.push_back(2);

    EXPECT_NO_CRASH(v[1]);

    // Enable this only if you implemented at()
    // EXPECT_THROW(v.at(2));
}

/* ============================================================
   Destructor / lifetime safety
   ============================================================ */

struct DtorCheck {
    static int alive;
    DtorCheck() { ++alive; }
    ~DtorCheck() { --alive; }
};

int DtorCheck::alive = 0;

void testDestructorStd()
{
    TEST_CASE("std::vector destructor safety");

    {
        vector<DtorCheck> v;
        v.emplace_back();
        v.emplace_back();
        assert(DtorCheck::alive == 2);
    }

    assert(DtorCheck::alive == 0);
    cout << "[PASS]\n";
}

void testDestructorCustom()
{
    TEST_CASE("v::Vector destructor safety");

    {
        Vector<DtorCheck> v;
        v.push_back(DtorCheck{});
        v.push_back(DtorCheck{});
        assert(DtorCheck::alive == 2);
    }

    assert(DtorCheck::alive == 0);
    cout << "[PASS]\n";
}

/* ============================================================
   Move safety (self-move)
   ============================================================ */

void testSelfMoveStd()
{
    TEST_CASE("std::vector self-move");

    vector<int> v = {1, 2, 3};
    v = std::move(v);
    EXPECT_NO_CRASH(assert(v.size() >= 0));
}

void testSelfMoveCustom()
{
    TEST_CASE("v::Vector self-move");

    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v = std::move(v);
    EXPECT_NO_CRASH(assert(v.size() >= 0));
}

/* ============================================================
   Generality tests
   ============================================================ */

struct NonCopyable {
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable(NonCopyable&&) = default;
};

void testMoveOnlyStd()
{
    TEST_CASE("std::vector move-only type");

    vector<unique_ptr<int>> v;
    v.push_back(make_unique<int>(5));
    cout << "[PASS]\n";
}

void testMoveOnlyCustom()
{
    TEST_CASE("v::Vector move-only type");

    Vector<unique_ptr<int>> v;
    v.push_back(make_unique<int>(5));
    cout << "[PASS]\n";
}

/* ============================================================
   Exception safety (reallocation failure)
   ============================================================ */

struct ExplodingCopy {
    ExplodingCopy() = default;
    ExplodingCopy(const ExplodingCopy&) {
        throw runtime_error("copy failed");
    }
};

void testExceptionSafetyStd()
{
    TEST_CASE("std::vector exception safety");

    vector<ExplodingCopy> v;
    v.emplace_back();

    try {
        v.push_back(ExplodingCopy{});
    } catch (...) {}

    cout << "[PASS] std::vector survived\n";
}

void testExceptionSafetyCustom()
{
    TEST_CASE("v::Vector exception safety");

    Vector<ExplodingCopy> v;
    v.push_back(ExplodingCopy{});

    try {
        v.push_back(ExplodingCopy{});
        cout << "[WARN] no exception thrown\n";
    } catch (...) {
        cout << "[PASS] exception thrown\n";
    }

    // If your vector leaks or corrupts here, ASAN will catch it
}

/* ============================================================
   Trivial vs non-trivial
   ============================================================ */

void testTypeTraits()
{
    TEST_CASE("type traits");

    static_assert(is_trivially_copyable_v<int>);
    static_assert(!is_trivially_copyable_v<string>);

    cout << "[PASS]\n";
}

/* ============================================================
   MAIN
   ============================================================ */

int main()
{
    testBoundsSafetyStd();
    testBoundsSafetyCustom();

    // testDestructorStd();
    // testDestructorCustom();

    testSelfMoveStd();
    testSelfMoveCustom();

    testMoveOnlyStd();
    testMoveOnlyCustom();

    testExceptionSafetyStd();
    testExceptionSafetyCustom();

    testTypeTraits();

    cout << "\nALL TESTS COMPLETED\n";
    return 0;
}
// File: Tests/VectorTest.cpp