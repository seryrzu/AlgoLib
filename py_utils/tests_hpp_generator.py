import os


def tests_hpp_generator(tests_fns, outfile, namespace, test_dir='tests'):
    N = len(tests_fns)
    tests_fns = ', '.join(['\"%s%s%s\"' % (test_dir, os.sep, fn) for fn in tests_fns])
    code = \
"""
#include <array>
#include <string_view>

namespace %s {
constexpr std::array<std::string_view, %d> tests_fns { %s };

} // End namespace %s
""" % (namespace, N, tests_fns, namespace)
    with open(outfile, 'w') as f:
        print(code, file=f)
